#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg");
    imshow("Origin",src);

    

    Rect ccomp;
    floodFill(src,Point(50,300),Scalar(0,0,255),&ccomp,Scalar(20,20,20),Scalar(20,20,20));
    println(ccomp);
    imshow("Result",src);

    src = imread("p1.jpg");
    
    floodFill(src,Point(100,100),Scalar(255,0 ,0),&ccomp);
    println(ccomp);
    imshow("Result2",src);

    waitKey(0);


    return 0;
}