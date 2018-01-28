#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("a1.jpg");
    imshow("Origin",src);

    Mat mid,dst;
    cvtColor(src,mid,COLOR_BGR2GRAY);
    GaussianBlur(mid,mid,Size(9,9),2,2);

    vector<Vec3f> circles;
    HoughCircles(mid,circles,3,1,1,100,200,0,0);
    println(circles.size());
    for(size_t i=0;i>circles.size();i++){
        Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(src,center,3,Scalar(0,255,0),-1,8,0);
        circle(src,center,radius,Scalar(155,50,255),3,8,0);
    }
    imshow("Effect",src);
    waitKey(0);
    return 0;
}
