#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat srcImage1 = imread("p1.jpg");
    Mat logoImage = imread("t3.jpg");

    if(!srcImage1.data){
        println("读取srcImage1错误~!");
        return -1;
    }
    if(!logoImage.data){
        println("读取logoImage错误~!");
        return -1;
    }
    
    Mat imageROI/*Region of Interest*/ = srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));

    logoImage.copyTo(imageROI);

    namedWindow("利用ROI实现图像叠加实例窗口1");
    imshow("利用ROI实现图像叠加实例窗口1",srcImage1);

    //读取的图片是灰色的
    Mat mask = imread("t3.jpg",0);

    imshow("TEST",mask);

    logoImage.copyTo(imageROI,mask);
    imshow("利用ROI实现图像叠加实例窗口2",srcImage1);

    waitKey(0);

    return 0;

}
