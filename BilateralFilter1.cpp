#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    Mat out;
    bilateralFilter(img,out,25,25*2,25/2);

    imshow("Result",out);

    waitKey(0);
    return 0;
}


