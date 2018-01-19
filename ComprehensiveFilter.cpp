#include"OpenCVLib2.hpp"
using namespace cv;

Mat g_srcImg,g_dstImg1,g_dstImg2,g_dstImg3;
int g_nBoxFilterValue = 3;
int g_nMeanBlurValue = 3;
int g_nGaussianBlurValue = 3;

static void on_BoxFilter(int,void*);
static void on_MeanBlur(int,void*);
static void on_GaussianBlur(int,void*);


int main(){

    //控制终端颜色(windows)
    system("color 5e");

    g_srcImg = imread("p1.jpg",IMREAD_COLOR);
    if(!g_srcImg.data){
        println("读取srcImg失败!");
        return -1;
    }

    g_dstImg1 = g_srcImg.clone();
    g_dstImg2 = g_srcImg.clone();
    g_dstImg2 = g_srcImg.clone();

    imshow("原始图像",g_srcImg);

    namedWindow("方框滤波",1);
    createTrackbar("内核值:","方框滤波",&g_nBoxFilterValue,40,on_BoxFilter);
    on_BoxFilter(g_nBoxFilterValue,0);

    namedWindow("均值滤波",1);
    createTrackbar("内核值:","均值滤波",&g_nMeanBlurValue,40,on_MeanBlur);
    on_MeanBlur(g_nMeanBlurValue,0);

    namedWindow("高斯滤波",1);
    createTrackbar("内核值:","高斯滤波",&g_nGaussianBlurValue,40,on_GaussianBlur);
    on_GaussianBlur(g_nGaussianBlurValue,0);

    println();
    println("\t,请调整滚动条观察图像效果~");
    println("\t按下'q'键时,程序退出~!");
    

    while(char(waitKey(1)) != 'q');

    return 0;
}

static void on_BoxFilter(int,void*){
    boxFilter(g_srcImg,g_dstImg1,-1,Size(g_nBoxFilterValue+1,g_nBoxFilterValue+1));
    imshow("方框滤波",g_dstImg1);
}
static void on_MeanBlur(int,void*){
    blur(g_srcImg,g_dstImg2,Size(g_nMeanBlurValue+1,g_nMeanBlurValue+1));
    imshow("均值滤波",g_dstImg2);
}
static void on_GaussianBlur(int,void *){
    GaussianBlur(g_srcImg,g_dstImg3,Size(g_nGaussianBlurValue*2+1,g_nGaussianBlurValue*2+1),0,0);
    imshow("高斯滤波",g_dstImg3);
}

