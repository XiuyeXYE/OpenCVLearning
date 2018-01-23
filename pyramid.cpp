#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("t1.jpg");

    Mat dst1,dst2;

    imshow("Origin",src);

    pyrUp(src,dst1,Size(src.cols*2,src.rows*2)/*default is this*/);
    imshow("dst1",dst1);

    pyrDown(src,dst2,Size(src.cols/2,src.rows/2)/*this is default*/);
    imshow("dst2",dst2);

    waitKey(0);
    return 0;
}