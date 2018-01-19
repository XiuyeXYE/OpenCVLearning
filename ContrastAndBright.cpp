#include"OpenCVLib2.hpp"
using namespace cv;

static void on_ContrastAndBright(int,void *);
static void ShowHelpText();

int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImg,g_dstImg;
/**
 * 图像对比度,亮度
 * 
 * Formula:
 *      g(x) = a*f(x) + b
 * 运用在实际中就是图片的像素
 * g(i,j) = a*f(i,j) + b
 * 像素不是单通道,每个通道都用如上公式. 
 * 
 * a--一般控制图像的对比度;
 * b--一般控制图像的亮度.
 * 
 */ 
int main(){
    g_srcImg = imread("p1.jpg");
    if(!g_srcImg.data){
        println("读取g_srcImg图片失败!");
        return -1;
    }

    imshow("原始图窗口",g_srcImg);

    g_dstImg = Mat::zeros(g_srcImg.size(),g_srcImg.type());

    g_nContrastValue = 80;
    g_nBrightValue = 80;
    namedWindow("效果图窗口",1);
    //参数:tracker name,依附的窗口name,绑定的变量,tracker最大值,事件回调函数
    createTrackbar("对比度:","效果图窗口",&g_nContrastValue,300,on_ContrastAndBright);
    createTrackbar("亮度:","效果图窗口",&g_nBrightValue,200,on_ContrastAndBright);
    //用事件函数初始化窗口
    on_ContrastAndBright(g_nContrastValue,0);
    on_ContrastAndBright(g_nBrightValue,0);

    waitKey(0);

    return 0;

}

static void on_ContrastAndBright(int,void *){

   
    for(int y=0;y<g_srcImg.rows;y++){
        for(int x=0;x<g_srcImg.cols;x++){
            for(int i=0;i<3;i++){
                g_dstImg.at<Vec3b>(y,x)[i] = /*saturate_cast防止数据overflow*/
                saturate_cast<uchar>((g_nContrastValue*0.01)*g_srcImg.at<Vec3b>(y,x)[i]+g_nBrightValue);
                
            }
        }
    }
    
    imshow("效果图窗口",g_dstImg);

}
