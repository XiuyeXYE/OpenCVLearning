#include"OpenCVLib.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
int main(){

    Mat srcImage = imread("monkeyKing.jpg");
    imshow("Original Picture:",srcImage);
    Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
    Mat destImage;
    erode(srcImage,destImage,element);
    imshow("New Picture after erode",destImage);
    waitKey(0);


    return 0;
}
