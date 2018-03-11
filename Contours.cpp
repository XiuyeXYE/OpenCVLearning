#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg",0);
    imshow("Origin",src);

    Mat dst = Mat::zeros(src.rows,src.cols,CV_8UC3);
    src = src > 199;

    imshow("threshold pic",src);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(src,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_SIMPLE);

    int index = 0;
    for(;index >= 0;index = hierarchy[index][0]){
        Scalar color(rand()&255,rand()&255,rand()&255);
        drawContours(dst,contours,index,color,CV_FILLED,8,hierarchy);

    }

    imshow("Effect",dst);

    waitKey(0);
    return 0;
}