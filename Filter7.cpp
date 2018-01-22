#include"OpenCVLib2.hpp"
using namespace cv;


int main(){

    Mat srcImg = imread("p1.jpg");
    imshow("Origin",srcImg);

    Mat&& dstImg = MyBlackHatFilter(srcImg,5);
    imshow("Black Hat 5x5",dstImg);

    dstImg = MyTopHatFilter(srcImg,5);
    imshow("Top Hat 5x5",dstImg);

    dstImg = MyMorphologicalGradientFilter(srcImg,5);
    imshow("Morphological Gradient",dstImg);

    waitKey(0);
    return 0;
}