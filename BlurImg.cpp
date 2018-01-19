#include"OpenCVLib.hpp"
using namespace cv;

int main(){

    Mat srcImg = imread("monkeyKing.jpg");
    imshow("Origin Picture:",srcImg);

    Mat destImg;

    blur(srcImg,destImg,Size(18,18));

    imshow("Result:",destImg);

    waitKey(0);

    return 0;
}


