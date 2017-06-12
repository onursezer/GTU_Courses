#include <iostream>
#include <vector>
#include <math.h>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

using namespace cv;
using namespace std;

#define PI 3.14159265
#define RMIN 10
#define RMAX 50
#define CIRCLE 80
#define VOTING 40

void houghTransform(Mat &edges,vector< Point > myEdges, int rmin, int rmax);
void findCircle(Mat &edges, int x, int y, int r);
void wrapper(Mat &img,Mat &edges);

Mat frame;
Mat voting;
int accumulator[120][160][200];
double myCos[120];
double mySin[120];
int main()
{
	VideoCapture cap(0); 
	if (!cap.isOpened()) 
		return -1;
	
	int choice;
	cout << "Enter a mode (1 or 2)" << endl; 
	cin >> choice;

	Mat edges;
	voting.create(Size(160,120), CV_8UC3);

	time_t start, end;
	int counter = 0;

	double t;
	for (int i = 0; i < 360; i+=3)
	{
		t = ((double)i * PI) / 180;
		myCos[i/3] = cos(t);
		mySin[i/3] = sin(t);
	}

	if(choice == 2)
	{
		char c;
		for(;;)
		{
			Mat out;
			cin.get();
			cap >> frame;
			resize(frame, out, Size(frame.cols * 0.25, frame.rows * 0.25), 0.25, 0.25, CV_INTER_LINEAR);
			wrapper(out,edges);
			if (waitKey(30) >= 0)
				break;
			imshow("edges", edges);
			imshow("frame", frame);
			imshow("Voting space", voting);
		}
	}
	else if(choice == 1)
	{
		for (;;)
		{
			if (counter == 0){
				time(&start);
			}
			cap >> frame; // get a new frame from camera
			
			Mat out;
			resize(frame, out, Size(frame.cols * 0.25, frame.rows * 0.25), 0.25, 0.25, CV_INTER_LINEAR);
			
			wrapper(out,edges);

			////////////// FPS CALCULATE //////////////
			time(&end);
			++counter;
			double sec = difftime(end, start);
			double fps = counter / sec;
			char fpsText[20];
			sprintf(fpsText, "FPS: %.2lf", fps);
			putText(frame, fpsText, Point(20, 20), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.6, Scalar(0, 0, 255), 2);
			//cout << fpsText << endl;
			///////////////////////////////////////////

			imshow("edges", edges);
			imshow("frame", frame);
			imshow("Voting space", voting);
			if (waitKey(30) >= 0)
				break;
		}
	}
	
	return 0;

}
void houghTransform(Mat &edges,vector< Point > myEdges, int rmin, int rmax){

	int maxRadius = ceil(sqrt((double)edges.rows*edges.rows + (double)edges.cols*edges.cols)/2);


	for (int i = 0; i < edges.rows; i++)
	{
		for (int j = 0; j < edges.cols; j++)
		{
			for (int k = 0; k < maxRadius; k++)
			{
				accumulator[i][j][k] = 0;
			}
		}
	}

	int x0, y0;
	double t;
	for (int i = 0; i < myEdges.size(); i++)
	{
		Point p = myEdges[i];
		for (int r = rmin; (r < rmax && r< maxRadius); ++r){
			for (int theta = 0; theta<360; theta += 3) {
				//t = ((double)theta * PI) / 180;
				x0 = (int)ceil(p.x - r * myCos[theta/3]);
				y0 = (int)ceil(p.y - r * mySin[theta/3]);
				//cout << "x0 : " << x0 << " y0 : " << y0 << endl;
				if (x0 < edges.rows && x0 > 0 && y0 < edges.cols && y0 > 0) {
					accumulator[x0][y0][r]++;
				}
			}
		}
	}
	findCircle(edges, edges.rows, edges.cols, maxRadius);
}
void findCircle(Mat &edges, int x, int y, int r)
{
	int max = 0, maxr=0, mx=0, my=0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < r; k++){
				if (accumulator[i][j][k] > CIRCLE){
					mx = i;
					my = j;
					maxr = k;
					circle(frame, Point(my*4, mx*4), maxr*4, Scalar(0, 255, 255), 2, 8);
					circle(frame, Point(my*4, mx*4), 2, Scalar(0, 0, 255), 2, 8);
				}
				//voting.at<type>(i,j) = accumulator[i][j][k];
				voting.at<Vec3b>(i, j)[0] += accumulator[i][j][k];
				voting.at<Vec3b>(i, j)[1] += accumulator[i][j][k];
				voting.at<Vec3b>(i, j)[2] += accumulator[i][j][k];
			}
		}

	}
}
void wrapper(Mat &img, Mat &edges)
{
	cvtColor(img, edges, COLOR_BGR2GRAY);
	GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
	Canny(edges, edges, 50, 150, 3);
	
	int edgesOfRows = edges.rows;
	int edgesOfCols = edges.cols;
	vector< Point > myEdges;
	int bin;
	for (int i = 0; i < edgesOfRows; i++)
	{
		for (int j = 0; j < edgesOfCols; j++)
		{	
			bin = (int)edges.at<uchar>(i, j);
			if (bin == 255)
				myEdges.push_back(Point (i,j));
		}
	}
	//cout << "myEdges : " << myEdges.size() << endl;

	voting = Scalar::all(0);
	houghTransform(edges, myEdges, RMIN, RMAX);

}