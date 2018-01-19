#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg");
    imshow("Origin",src);

    Rect ccomp;
    floodFill(src,Point(50,300),Scalar(155,255,55),&ccomp,Scalar(20,20,20),Scalar(20,20,20));
    imshow("Result",src);

    waitKey(0);


    return 0;
}