#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat srcImage1 = imread("p1.jpg");
    Mat logoImage = imread("t3.jpg");

    if(!srcImage1.data){
        println("��ȡsrcImage1����~!");
        return -1;
    }
    if(!logoImage.data){
        println("��ȡlogoImage����~!");
        return -1;
    }
    
    Mat imageROI/*Region of Interest*/ = srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));

    logoImage.copyTo(imageROI);

    namedWindow("����ROIʵ��ͼ�����ʵ������1");
    imshow("����ROIʵ��ͼ�����ʵ������1",srcImage1);

    //��ȡ��ͼƬ�ǻ�ɫ��
    Mat mask = imread("t3.jpg",0);

    imshow("TEST",mask);

    logoImage.copyTo(imageROI,mask);
    imshow("����ROIʵ��ͼ�����ʵ������2",srcImage1);

    waitKey(0);

    return 0;

}
