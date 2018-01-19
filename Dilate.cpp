#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    Mat element = getStructuringElement(MORPH_RECT,Size(5,5));
    // println("Element",element);//不要输出,否则运行时后面窗口一闪即逝,

    Mat out;
    dilate(img,out,element);

    imshow("Out",out);

    waitKey(0);

    return 0;
}