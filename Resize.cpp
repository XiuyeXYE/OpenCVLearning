#include"OpenCVLib2.hpp"
#include<windows.h>
using namespace cv;

int main(){

    Mat srcImg = imread("p1.jpg");
    imshow("Origin",srcImg);

    Mat dstImg;
    resize(srcImg,dstImg,Size(srcImg.cols/2,srcImg.rows/2),(0,0),(0,0),3);
    imshow("/2",dstImg);

    resize(srcImg,dstImg,Size(srcImg.cols*2,srcImg.rows*2),(0,0),(0,0),3);
    namedWindow("*2",WINDOW_AUTOSIZE|WS_HSCROLL);
    imshow("*2",dstImg);

    waitKey(0);
    return 0;
}