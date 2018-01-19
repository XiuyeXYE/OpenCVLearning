#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    Mat out;
    medianBlur(img,out,7);

    imshow("Result:",out);
    waitKey(0);

    return 0;
}