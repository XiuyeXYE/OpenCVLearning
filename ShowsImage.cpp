#include"OpenCVLib.hpp"
#include<opencv2/opencv.hpp>
using namespace cv;
int main(){

    Mat mat = imread("monkeyKing.jpg");
    imshow("Origin picture:",mat);
    waitKey(0);


    return 0;
}