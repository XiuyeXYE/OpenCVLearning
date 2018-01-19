#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat srcImg = imread("p1.jpg");
    imshow("Origin",srcImg);

    //Open Op = dilate(erode(src,element))
    Mat&& dstImg = MyDilateFilter(MyErodeFilter(srcImg,15),15);
    imshow("Open Op 15x15",dstImg);
    //Closing Op = erode(dilate(rsc,element))
    dstImg = MyErodeFilter(MyDilateFilter(srcImg,15),15);
    imshow("Closing Op 15x15",dstImg);
    waitKey(0);
    return 0;
}