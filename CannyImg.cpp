#include"OpenCVLib.hpp"
using namespace cv;

int main(){

    Mat srcImg = imread("monkeyKing.jpg");
    imshow("Origin Picture:",srcImg);
    
    Mat edge,grayImg;
    //将原图像转化为灰度图像
    cvtColor(srcImg,grayImg,CV_BGR2GRAY);
    //先使用3*3内核来降噪
    blur(grayImg,edge,Size(3,3));
    //运算canny算子
    Canny(edge,edge,3,9,3);
    imshow("Result:",edge);


    waitKey(0);

    return 0;
}

