#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat srcImg = imread("p1.jpg");
    imshow("Origin",srcImg);

    Mat&& dstImg = MySmallTwice(srcImg);

    imshow("Small Twice Pic",dstImg);

    waitKey(0);
    return 0;
}
