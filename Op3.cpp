#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat grad_x,grad_y;
    Mat abs_grad_x,abs_grad_y,dst;

    Mat src = imread("p1.jpg");
    imshow("Origin",src);

    Sobel(src,grad_x,CV_16S,1,0,3,1,1,BORDER_DEFAULT);
    convertScaleAbs(grad_x,abs_grad_x);
    imshow("X-axis",abs_grad_x);

    Sobel(src,grad_y,CV_16S,0,1,3,1,1,BORDER_DEFAULT);
    convertScaleAbs(grad_y,abs_grad_y);
    imshow("Y-axis",abs_grad_y);

    addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0,dst);
    imshow("X-Y-axis",dst);

    waitKey(0);
    return 0;
}