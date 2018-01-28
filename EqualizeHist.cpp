#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg");
    imshow("Origin",src);

    Mat dst;
    cvtColor(src,src,COLOR_BGR2GRAY);
    imshow("Gray",src);
    equalizeHist(src,dst);
    imshow("Hist",dst);

    waitKey(0);
    return 0;
}
