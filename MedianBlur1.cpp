#include"OpenCVLib2.hpp"
using namespace cv;



int main(){
    TimeSpec::begin();

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    Mat out;
    medianBlur(img,out,7);

    TimeSpec::print_cost_time();

    imshow("Result:",out);
    waitKey(0);

    return 0;
}