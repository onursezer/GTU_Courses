//
// Created by recep on 4/29/17.
//

#include "Frame.h"

int Frame::getX() const {
    return x;
}

void Frame::setX(int x) {
    Frame::x = x;
}

int Frame::getY() const {
    return y;
}

void Frame::setY(int y) {
    Frame::y = y;
}

 Mat &Frame::getImage()  {
    return Image;
}

void Frame::setImage(const Mat &Image) {
    Frame::Image = Image;
}

Frame::Frame() {}

Frame::Frame(int x, int y,  Mat Image) : x(x), y(y), Image(Image) {}

int Frame::getTotalPixel() const {
    return totalPixel;
}

void Frame::setTotalPixel(int totalPixel) {
    Frame::totalPixel = totalPixel;
}
