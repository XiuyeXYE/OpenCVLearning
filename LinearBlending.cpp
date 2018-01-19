#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    /**
     * Math Formula :
     *  g(x) = (1-a)*f1(x) + a*f2(x) + gama
     * 
     * Formula: 
     * dst = src1[I]*alpha + src2[I]*beta + gama;
     * 每个通道都需要独立的处理.
     */ 
    double alphaValue = 0.5;
    double betaValue;
    Mat src1Img,src2Img,dstImg;
    src1Img = imread("t2.jpg");
    src2Img = imread("t3.jpg");

    if(!src1Img.data){

        println("读取src1Img错误~!");
        return -1;
    }
    if(!src2Img.data){

        println("读取src2Img错误~!");
        return -1;
    }
    betaValue = 1.0 - alphaValue;
    //src1Img 和 src3Img 必须具有相同大小,否则即使编译通过,运行时也会报错!
    addWeighted(src1Img,alphaValue,src2Img,betaValue,0,dstImg);

    imshow("线性混合实例窗口[原图]",src1Img);
    imshow("线性混合实例窗口[效果图]",dstImg);

    waitKey(0);

    return 0;
}


