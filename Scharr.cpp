#include"OpenCVLib2.hpp"
using namespace cv;


int main(){

    Mat grad_x,grad_y;
    Mat abs_grad_x,abs_grad_y,dst;

    Mat src = imread("p1.jpg");
    imshow("Origin",src);

    Scharr(src,grad_x,CV_16S,1,0,1,0,BORDER_DEFAULT);
    convertScaleAbs(grad_x,abs_grad_x);
    imshow("x",abs_grad_x);

    Scharr(src,grad_y,CV_16S,0,1,1,0,BORDER_DEFAULT);
    convertScaleAbs(grad_y,abs_grad_y);
    imshow("y",abs_grad_y);

    addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0,dst);

    imshow("xy",dst);

    waitKey(0);
    return 0;
}