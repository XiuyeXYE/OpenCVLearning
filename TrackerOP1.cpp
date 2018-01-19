#include"OpenCVLib.hpp"
using namespace cv;

#define WINDOW_NAME "TEST"

const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;


void on_Tackbar(int,void *){
    g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
    g_dBetaValue = (1.0 - g_dAlphaValue);
    addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);
    imshow(WINDOW_NAME,g_dstImage);
}

int main(){

    g_srcImage1 = imread("t3.jpg");
    g_srcImage2 = imread("t2.jpg");
    if(!g_srcImage1.data){
        std::cout << "Failed to read first pic" << std::endl;
        return -1;
    }
    if(!g_srcImage2.data){
        std::cout << "Failed to read second pic" << std::endl;
        return -2;
    }
    g_nAlphaValueSlider = 70;
    namedWindow(WINDOW_NAME,1);
    char TrackbarName[50];
    sprintf(TrackbarName,"Alpha Max Value : %d",g_nMaxAlphaValue);
    createTrackbar(TrackbarName,WINDOW_NAME,&g_nAlphaValueSlider,g_nMaxAlphaValue,on_Tackbar);

    //first show <=> updateWindow
    on_Tackbar(g_nAlphaValueSlider,0);


    waitKey(0);

    return 0;
}


