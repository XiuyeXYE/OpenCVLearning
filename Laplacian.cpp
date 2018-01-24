#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src,src_gray,dst,abs_dst;
    src = imread("p1.jpg");
    imshow("Origin",src);

    GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);

    cvtColor(src,src_gray,COLOR_RGB2GRAY);

    Laplacian(src_gray,dst,CV_16S,3,1,0,BORDER_DEFAULT);

    convertScaleAbs(dst,abs_dst);

    imshow("laplacian",abs_dst);

    waitKey(0);
    return 0;
}
