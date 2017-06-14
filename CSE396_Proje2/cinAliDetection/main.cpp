#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <string>
#include "Frame.h"
#include<iostream>
#include <cmath>

using namespace std;
using namespace cv;
void SobelFilter(Mat &image1);

//RNG rng(12345);
int returnNumberOfEdgePixels(Mat image1);
bool detectStickMan(Mat &src);
int rotasyon(Mat src_mat);

int main() {


    vector<Frame> frameList;
    vector<Frame> realFrameL;

    VideoCapture cap(0);
    int j=0;

    /*while (j<50)
    {
        Mat frame;

        cout<<"asasadasd"<<endl;

        cap >> frame;

        //imshow("deneme", frame);
        ++j;
        frameList.push_back(Frame(0,0,frame));
        realFrameL.push_back(Frame(0,0,frame));
        imshow("deneme",frame);
        waitKey(5);
    }*/

    while (1)
    {
        Mat frame;
        cap >> frame;
        ++j;
        //frameList.push_back(Frame(0,0,frame));
        //realFrameL.push_back(Frame(0,0,frame));
        imshow("deneme",frame);
        waitKey(5);
        //SobelFilter(frame);
        detectStickMan(frame);
        rotasyon(frame);
    }

    // string str="";
    // for(int a =0 ;a<frameList.size();++a) // cektigi resimleri klasore yazar
    // {

    //     string path("/home/onur/Desktop/Notlar/proje/resim/");
    //     string Result;          // string which will contain the result

    //     ostringstream convert;   // stream used for the conversion

    //     convert << a;      // insert the textual representation of 'Number' in the characters in the stream

    //     Result = convert.str();
    //     path += Result;
    //     path += ".jpg";
    //     cout << "path : " << path << endl;
    //     imwrite(path, frameList.at(a).getImage());
    // }

    // int total,i=0,max = 0;
    // //Binary image
    // for(int j=0;j<frameList.size();++j)  // framelerin yogunlarini set eder
    // {
    //     SobelFilter(frameList[j].getImage());
    //     total=returnNumberOfEdgePixels(frameList[j].getImage());
    //     frameList[j].setTotalPixel(total);
    //     cout << "total : " << total << endl;
    //     if(j==0)
    //     {
    //         max=total;

    //     }
    //     if(max<total)
    //         max=total;

    // }
    int totalX = 0, totalY = 0, size = 0, avX, avY,maxFrameLoc=-1;
    // // yogunlugu max. esit olan framelerin kordinatalarından ortalama
    // // x ve y indexi bulur
    // for(int j=0;j<frameList.size();++j)
    // {
    //     if(max==frameList[j].getTotalPixel())
    //     {
    //         size++;
    //         totalX += frameList[j].getX();
    //         totalY += frameList[j].getY();
    //         maxFrameLoc = j;
    //     }
    // }

    // rotasyon(realFrameL[maxFrameLoc].getImage(),frameList[maxFrameLoc].getImage());

    rotasyon(frameList[maxFrameLoc].getImage());

    imshow("MaxFrame",frameList[maxFrameLoc].getImage());

    avX = totalX / size;
    avY = totalY / size;

    cout << "Ortalama X : " << avX << " Ortalama Y : " << avY << endl;

    waitKey(0);
    return 0;
}

bool detectStickMan(Mat& src) {
    cerr<<"Here"<<endl;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    //filters
    cv::Mat binaryMat(src.size(), src.type());
    GaussianBlur(src, src, Size(3, 3), 2);
    Canny(src, binaryMat, 40, 120, 3);

    dilate(binaryMat, binaryMat, getStructuringElement(MORPH_RECT, Size(5, 5)));
    //imshow("binary", src);
    //waitKey(1);

    /// Find contours
    findContours(binaryMat, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    /// Find the rotated rectangles and ellipses for each contour
    vector<RotatedRect> minRect(contours.size());
    vector<RotatedRect> minEllipse(contours.size());
    vector<int> elipseIndex;

    double area = 0, maxArea = 0;
    int index = 0;
    for (int i = 0; i < contours.size(); i++) {
        minRect[i] = minAreaRect(Mat(contours[i]));
        area = contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = area;
            index = i;
        }
        if (contours[i].size() > 50) {
            elipseIndex.push_back(i);
            minEllipse[i] = fitEllipse(Mat(contours[i]));
        }
    }
    int maxElips, minElips;
    if (elipseIndex.size() == 2) {
        int i, j, plusAngle;
        i = elipseIndex[0];
        j = elipseIndex[1];
        if (minEllipse[i].size.area() > minEllipse[j].size.area()) {
            maxElips = i;
            minElips = j;
        } else {
            maxElips = j;
            minElips = i;
        }
        double rate = 0;
        if (minEllipse[maxElips].size.height < minEllipse[maxElips].size.width) {
            rate = minEllipse[minElips].size.width / minEllipse[minElips].size.height;
        } else if (minEllipse[maxElips].size.height > minEllipse[maxElips].size.width) {
            rate = minEllipse[minElips].size.height / minEllipse[minElips].size.width;
        } else
            rate = 1;

        int maxMinEl, maxMaxEl;

        // min elipsin max capi
        if (minEllipse[maxElips].size.width > minEllipse[maxElips].size.height)
            maxMinEl = minEllipse[maxElips].size.width;
        else
            maxMinEl = minEllipse[maxElips].size.height;
        // max elipsin max capi
        if (minEllipse[minElips].size.width > minEllipse[minElips].size.height)
            maxMaxEl = minEllipse[minElips].size.width;
        else
            maxMaxEl = minEllipse[minElips].size.height;

        if (minRect[index].boundingRect().contains(minEllipse[maxElips].center)
            && rate < 2 && minRect[index].boundingRect().area() > 20000
            && (maxMaxEl / maxMinEl) < 2) {
            cout << "buldu " << endl;
            return true;
        }
        return false;
    }
    return false;
}
int rotasyon(Mat src){
    double angle = -1;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    cv::Mat binaryMat(src.size(), src.type());
    GaussianBlur(src,src,Size(3,3),2);
    Canny(src,binaryMat,40,120,3);
    dilate(binaryMat,binaryMat,getStructuringElement(MORPH_RECT,Size(5,5)));
    imshow("binary", binaryMat);

    /// Find contours
    findContours( binaryMat, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    /// Find the rotated rectangles and ellipses for each contour
    vector<RotatedRect> minRect( contours.size() );
    vector<RotatedRect> minEllipse( contours.size() );
    vector<int> elipseIndex;
    /*cout<<endl<<contours[1]<<endl;
    cout<<endl<<Mat(contours[1])<<endl;*/

    Mat drawing = Mat::zeros( binaryMat.size(), CV_8UC3 );
    double area = 0, maxArea = 0;
    int index = 0;
    for( int i = 0; i < contours.size(); i++ )
    {
        minRect[i] = minAreaRect( Mat(contours[i]) );
        area = contourArea(contours[i]);
        if(area > maxArea) {
            maxArea = area;
            index = i;
        }
        if( contours[i].size() > 50 )
        {
            elipseIndex.push_back(i);
            minEllipse[i] = fitEllipse( Mat(contours[i]) );
            circle(drawing, Point(minEllipse[i].center.x, minEllipse[i].center.y), 2, Scalar(0, 255, 255), 2, 8);
        }
    }
    //cout << "elipseIndex.size : " << elipseIndex.size() << endl;
    if(elipseIndex.size() == 2) {
        double bX, bY, sX, sY;
        int i, j, plusAngle;
        i = elipseIndex[0]; j = elipseIndex[1];
        if( minEllipse[i].size.area() > minEllipse[j].size.area())
        {
            //cout << "buyuk : " << minEllipse[i].center << " kucuk : " << minEllipse[j].center << endl;
            bY = minEllipse[i].center.x;
            bX = minEllipse[i].center.y;
            sY = minEllipse[j].center.x;
            sX = minEllipse[j].center.y;
        }
        else
        {
            //cout << "buyuk : " << minEllipse[j].center << " kucuk : " << minEllipse[i].center << endl;
            bY = minEllipse[j].center.x;
            bX = minEllipse[j].center.y;
            sY = minEllipse[i].center.x;
            sX = minEllipse[i].center.y;
        }
        //cout << "bX: " << bX << " bY : " << bY << " sX : " << sX <<  " sY :" << sY << endl;
        // find zone
        if ((bX > sX) && (bY < sY)) {
            angle = 90 - (atan((sY - bY) / ( bX - sX)) * 180 / CV_PI);
            //cout << "1" << endl;
        } else if ((bX > sX) && (bY > sY)) {
            angle = atan((bY - sY) / ( bX - sX)) * 180 / CV_PI;
            plusAngle = 90;
            angle += plusAngle;
            //cout << "2" << endl;
        } else if ((bX < sX) && (bY > sY)) {
            angle = atan( ( sX - bX) / (bY - sY)) * 180 / CV_PI;
            plusAngle = 180;
            angle += plusAngle;
            //cout << "3" << endl;
        } else if ((bX < sX) && (bY < sY)) {
            angle = atan( (sY - bY) / ( sX - bX)) * 180 / CV_PI;
            plusAngle = 270;
            angle += plusAngle;
            // cout << "4" << endl;
        } else if ((bX == sX) && (sY > bY)) {
            //cout << "5" << endl;
            angle = 0;
        } else if ((bX == sX) && (sY < bY)) {
            //cout << "6" << endl;
            angle = 180;
        } else if ((bX > sX) && (sY == bY)) {
            //cout << "7" << endl;
            angle = 90;
        } else if ((bX < sX) && (sY == bY)) {
            //cout << "8" << endl;
            angle = 270;
        } else
            cout << "girmedi" << endl;


        /// Draw contours + rotated rects + ellipses
        for( int i = 0; i< contours.size(); i++ )
        {
            //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
            // contour
            drawContours( drawing, contours, i, Scalar(255,255,255), 1, 8, vector<Vec4i>(), 0, Point() );
            // ellipse
            ellipse( drawing, minEllipse[i], Scalar(0,255,255), 2, 8 );
            // rotated rectangle
            Point2f rect_points[4]; minRect[i].points( rect_points );
            for( int j = 0; j < 4; j++ )
                line( drawing, rect_points[j], rect_points[(j+1)%4], Scalar(0,0,255), 1, 8 );
        }
        /// Show in a window
        namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
        imshow( "Contours", drawing );

        if(angle == -1) {
            cout << "angle : " << abs(minRect[index].angle) << endl;
            angle = abs(minRect[index].angle) + plusAngle;
            //cout << "angle : " << abs(minRect[index].angle) << " plusAngle : " << plusAngle << endl;
        }
        cout << "**********  angle : " << (int)angle << "  **********"<< endl;
        return  angle;
    } else {
        cerr << "No angle" << endl;
        for( int i = 0; i< contours.size(); i++ )
        {
            //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
            // contour
            drawContours( drawing, contours, i, Scalar(0,255,0), 1, 8, vector<Vec4i>(), 0, Point() );
            // ellipse
            ellipse( drawing, minEllipse[i], Scalar(0,255,255), 2, 8 );
            // rotated rectangle
            Point2f rect_points[4]; minRect[i].points( rect_points );
            for( int j = 0; j < 4; j++ )
                line( drawing, rect_points[j], rect_points[(j+1)%4], Scalar(0,0,255), 1, 8 );
        }
        /// Show in a window
        namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
        imshow( "Contours", drawing );
        return -1;
    }
}
void SobelFilter(Mat &image1)
{
    GaussianBlur( image1, image1, Size(5,5), 0, 0, BORDER_DEFAULT );

    /// Convert it to gray
    cvtColor( image1, image1, CV_BGR2GRAY );


    /// Generate grad_x and grad_y
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    /// Gradient X
    //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    Sobel( image1, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );

    /// Gradient Y
    //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    Sobel( image1, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs( grad_y, abs_grad_y );

    /// Total Gradient (approximate)
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, image1 );
}

void CannyEdgeDetection(Mat & image1)
{
    /// Create a matrix of the same type and size as src (for dst)
    image1.create( image1.size(), image1.type() );

    /// Convert the image to grayscale
    cvtColor( image1, image1, CV_BGR2GRAY );

    blur( image1, image1, Size(3,3) );

    /// Canny detector
    Canny( image1, image1, 15, 15*3, 3 );
}

int returnNumberOfEdgePixels(Mat image1)
{
    cv::Mat binaryMat(image1.size(), image1.type());

    //Apply thresholding
    cv::threshold(image1, binaryMat, 50, 255, cv::THRESH_BINARY);

    int total=0;

    for(int i=0;i<binaryMat.rows;++i)
    {
        for(int j=0;j<binaryMat.cols;++j)
        {
            if((int)binaryMat.at<uchar>(j,i)==255)
                ++total;
        }

    }
    return total;
}