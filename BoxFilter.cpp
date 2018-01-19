#include"OpenCVLib2.hpp"
using namespace cv;


int main(){

    Mat img = imread("p1.jpg");

    imshow("Origin",img);

    Mat out;
    boxFilter(img,out,-1,Size(5,5));

    imshow("Effect:",out);

    waitKey(0);


    return 0;
}