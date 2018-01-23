#include"OpenCVLib2.hpp"
using namespace cv;

#define WINDOW_NAME "Window"

int g_nThresholdValue = 100;
int g_nThresholdType = 3;
Mat g_srcImg,g_grayImg,g_dstImg;

void on_Threshold(int,void*);

int main(){

    g_srcImg = imread("p1.jpg");
    if(!g_srcImg.data){
        println("读取图像失败!");
        return -1;
    }
    
    cvtColor(g_srcImg,g_grayImg,COLOR_RGB2GRAY);

    namedWindow(WINDOW_NAME,WINDOW_AUTOSIZE);

    createTrackbar("模式",WINDOW_NAME,&g_nThresholdType,4,on_Threshold);

    createTrackbar("参数值",WINDOW_NAME,&g_nThresholdValue,255,on_Threshold);

    on_Threshold(0,0);

    waitKey(0);
    return 0;
}

void on_Threshold(int,void*){
    threshold(g_grayImg,g_dstImg,g_nThresholdValue,255,g_nThresholdType);
    imshow(WINDOW_NAME,g_dstImg);
}