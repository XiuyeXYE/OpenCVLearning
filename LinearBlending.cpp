#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    /**
     * Math Formula :
     *  g(x) = (1-a)*f1(x) + a*f2(x) + gama
     * 
     * Formula: 
     * dst = src1[I]*alpha + src2[I]*beta + gama;
     * ÿ��ͨ������Ҫ�����Ĵ���.
     */ 
    double alphaValue = 0.5;
    double betaValue;
    Mat src1Img,src2Img,dstImg;
    src1Img = imread("t2.jpg");
    src2Img = imread("t3.jpg");

    if(!src1Img.data){

        println("��ȡsrc1Img����~!");
        return -1;
    }
    if(!src2Img.data){

        println("��ȡsrc2Img����~!");
        return -1;
    }
    betaValue = 1.0 - alphaValue;
    //src1Img �� src3Img ���������ͬ��С,����ʹ����ͨ��,����ʱҲ�ᱨ��!
    addWeighted(src1Img,alphaValue,src2Img,betaValue,0,dstImg);

    imshow("���Ի��ʵ������[ԭͼ]",src1Img);
    imshow("���Ի��ʵ������[Ч��ͼ]",dstImg);

    waitKey(0);

    return 0;
}


