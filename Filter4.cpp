#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    //Parameters must be the same type!
    println(xy_max(2,1,4,5,22,99,11));
    println(xy_min(2,1,4,5,22,99,11));
    println(xy_max(22.2,33.3,2.2,3.0));
    println(xy_min(22.2,33.3,2.2,3.0));

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    Mat&& dstImg = MyDilateFilter(img,3);

    imshow("3x3",dstImg);

    dstImg = MyDilateFilter(img,5);

    imshow("5x5",dstImg);

    waitKey(0);

    return 0;
}