#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    Mat&& dstImg = MyErodeFilter(img,15);
    imshow("Erode 15x15",dstImg);

    dstImg = MyDilateFilter(img,15);
    imshow("Dilate 15x15",dstImg);

    waitKey(0);

    return 0;
}