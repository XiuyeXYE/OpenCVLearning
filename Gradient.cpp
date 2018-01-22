#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat srcImg = imread("p1.jpg");

    imshow("Origin",srcImg);

    //dilate(src,element) - erode(src,element)
    Mat&& dstImg = MyDilateFilter(srcImg,5) - MyErodeFilter(srcImg,5);
    imshow("Morphological Gradient 5x5",dstImg);

    //src - open(src,element);
    dstImg = srcImg - MyDilateFilter(MyErodeFilter(srcImg,5),5);
    imshow("Top Hat 5x5",dstImg);

    //close(src,element) - src
    dstImg = MyErodeFilter(MyDilateFilter(srcImg,5),5) - srcImg;
    imshow("BlackHat 5x5",dstImg);

    waitKey(0);
    return 0;
}