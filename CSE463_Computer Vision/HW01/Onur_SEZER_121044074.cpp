/**
*	121044074
*	Onur SEZER
*	Computer Vision HW1
*/
#include "opencv2/opencv.hpp"
#include <time.h>   // zamani hesaplamak icin kullanildi
#include <stdio.h>
 
using namespace cv;
using namespace std;

// frame i graye cevirir
void convertGray(Mat& source, Mat& dest);
// en parlak yeri bulur
int findFirst(Mat& source, int &mi, int &mj, int &dist);
// ikinci en parlak yeri bulur
void findSecond(Mat& source, int &mi, int &mj, int first,int &dist);
// ucuncu en parlak yeri bulur
void findThird(Mat& source, int &mi, int &mj, int first, int &dist); 
// parlaklıgı bulunan alanın ne kadar alan kapladıgı bulunur
void findDist(Mat& source, int first, int &dist);
	
int main(int argc, char** argv)
{
	VideoCapture cap(0);
	if (!cap.isOpened()) // check if we succeeded
	{
		cerr << "camera is not opened!\n";
		system("pause");
		return -1;	
	}
    time_t start, end;
    double sec;
    double fps;
	time(&start);
	int counter=0;
	Mat edges;
	int mi = 0, mj = 0, dist = 0;
	vector<Point> fVector;
	for (;;)
	{
		if (counter == 0){
            	  time(&start);
        	}
		Mat frame,img;
		cap >> frame; // get a new frame from camera

		convertGray(frame, img);

		int first = findFirst(img,mi,mj,dist);
		
		circle(frame, Point(mj,mi), dist, Scalar(0, 255, 0), 2, 8);
		putText(frame, "1", Point(mj, mi), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.8, Scalar(0, 255, 0), 2);

		findSecond(img, mi, mj, first,dist);
		circle(frame, Point(mj, mi), dist, Scalar(0, 0, 255), 2, 8);
		putText(frame, "2", Point(mj, mi), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.8, Scalar(0, 0, 255), 2);

		findThird(img, mi, mj, first,dist);
		circle(frame, Point(mj, mi), dist, Scalar(255, 0, 0), 2, 8);
		putText(frame, "3", Point(mj, mi), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.8, Scalar(255, 0, 0), 2);

		if (waitKey(5) >= 0)
			break;

		time(&end);
		++counter;
		double sec=difftime(end,start);
		double fps=counter/sec;
		char fpsText[20];
		sprintf(fpsText, "FPS: %.lf", fps);
		putText(frame, fpsText, Point(20, 20), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.8, Scalar(0, 255, 255),2);
		
		imshow("test", frame);

	}
	return 0;
}
void convertGray(Mat& source, Mat& dest)
{
	dest = source.clone();
	for (int i = 0; i < source.rows;++i)
		for (int j = 0; j < source.cols; ++j)
		{
			int value = (source.at<Vec3b>(i, j)[0] + source.at<Vec3b>(i, j)[1] + source.at<Vec3b>(i, j)[2]) / 3;
			dest.at<Vec3b>(i, j)[0] = value;
			dest.at<Vec3b>(i, j)[1] = value;
			dest.at<Vec3b>(i, j)[2] = value;
		}
}
int findFirst(Mat& source, int &mi, int &mj, int &dist)
{
	vector<Point> fVector;
	int first = 0;
	for (int i = 0; i < source.rows; ++i)
		for (int j = 0; j < source.cols; ++j)
		{
			if (source.at<Vec3b>(i, j)[0] > first){
				first = source.at<Vec3b>(i, j)[0];
				mi = i;
				mj = j;
			}
		}
	findDist(source, first, dist);
	return first;
}
void findSecond(Mat& source, int &mi, int &mj, int first,int &dist)
{
	int second = 0;
	vector<Point> fVector;
	for (int i = 0; i < source.rows; ++i)
		for (int j = 0; j < source.cols; ++j)
		{
			if (source.at<Vec3b>(i, j)[0] < (first - 70) && source.at<Vec3b>(i, j)[0] > second){
				second = source.at<Vec3b>(i, j)[0];
				mi = i;
				mj = j;
			}
		}
	findDist(source, second, dist);
}
void findThird(Mat& source, int &mi, int &mj, int first,int &dist)
{
	int third = 0;
	for (int i = 0; i < source.rows; ++i)
		for (int j = 0; j < source.cols; ++j)
		{
			if (source.at<Vec3b>(i, j)[0] < (first - 130) && source.at<Vec3b>(i, j)[0] > third){
				third = source.at<Vec3b>(i, j)[0];
				mi = i;
				mj = j;
			}
		}
	findDist(source, third, dist);
}
void findDist(Mat& source, int light,int &dist)
{
	vector<Point> fVector;
	for (int i = 0; i < source.rows; ++i)
		for (int j = 0; j < source.cols; ++j)
		{
			if (source.at<Vec3b>(i, j)[0] == light){
				fVector.push_back(Point(i, j));
			}
		}
	int max = 0, temp = 0, fi = 0, fj = 0;
	for (int i = 1; i<fVector.size(); i += 10)
	{
		for (int j = 0; j<fVector.size() - i; j += 10)
		{
			temp = abs(fVector[i].x - fVector[j].x);
			if (temp > max)
			{
				max = temp;
				fi = i; fj = j;
			}
		}
	}
	max = sqrt(pow((fVector[fi].x - fVector[fj].x), 2) + pow((fVector[fi].y - fVector[fj].y), 2));
	dist = max / 8;
}
