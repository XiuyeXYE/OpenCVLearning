#include"OpenCVLib2.hpp"
using namespace cv;
int main(){

    Mat src = imread("p1.jpg");
    imshow("Origin",src);

    Mat dst(src.rows*3,src.cols*3,src.type(),Scalar::all(0));

    println("rows = ",src.rows);
    println("cols = ",src.cols);

    double a[2][2] = {
        {0.2,0.5},
        {0.9,0.3}
        };
    double b[2][1] = {99,77};

    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){
            int x = a[0][0]*i+a[0][1]*j+b[0][0];
            int y = a[1][0]*i+a[1][1]*j+b[1][0];
            // println("x = ",x);
            // println("y = ",y);
            dst.at<Vec3b>(x,y)[0] = src.at<Vec3b>(i,j)[0];
            dst.at<Vec3b>(x,y)[1] = src.at<Vec3b>(i,j)[1];
            dst.at<Vec3b>(x,y)[2] = src.at<Vec3b>(i,j)[2];
        }
    }

    imshow("Effect",dst);

    waitKey(0);
    return 0;
}