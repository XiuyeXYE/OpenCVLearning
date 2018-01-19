#include"OpenCVLib2.hpp"
using namespace cv;



int main(){

    Mat img = imread("p1.jpg");
    imshow("Origin",img);
    
    Mat&& dstImg = MyMeanFilter(img,7);
    imshow("Effect1",dstImg);

    dstImg = MyMeanFilter(img,17);
    imshow("Effect2",dstImg);

    waitKey(0);

    return 0;
}