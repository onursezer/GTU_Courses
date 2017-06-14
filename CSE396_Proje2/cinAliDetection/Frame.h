//
// Created by recep on 4/29/17.
//

#ifndef CINALIDETECTION_FRAME_H
#define CINALIDETECTION_FRAME_H
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
using namespace cv;
class Frame {


private:
public:
    Frame(int x, int y,  Mat Image);

    Frame();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

     Mat &getImage();

    void setImage(const Mat &Image);

    int getTotalPixel() const;

    void setTotalPixel(int totalPixel);

private:
    int x;
    int y;
    Mat Image;
    int totalPixel;
};


#endif //CINALIDETECTION_FRAME_H
