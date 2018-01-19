#include"OpenCVLib.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(){

    Mat srcImg = imread("monkeyKing.jpg");    
    imshow("Origin Picture",srcImg);
    Mat element = getStructuringElement(MORPH_RECT,Size(200,200));
    imshow("Element",element);
    Mat destImg;
    erode(srcImg,destImg,element);
    imshow("Result:",destImg);

    waitKey(0);

}