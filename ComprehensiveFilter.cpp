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

    //�����ն���ɫ(windows)
    system("color 5e");

    g_srcImg = imread("p1.jpg",IMREAD_COLOR);
    if(!g_srcImg.data){
        println("��ȡsrcImgʧ��!");
        return -1;
    }

    g_dstImg1 = g_srcImg.clone();
    g_dstImg2 = g_srcImg.clone();
    g_dstImg2 = g_srcImg.clone();

    imshow("ԭʼͼ��",g_srcImg);

    namedWindow("�����˲�",1);
    createTrackbar("�ں�ֵ:","�����˲�",&g_nBoxFilterValue,40,on_BoxFilter);
    on_BoxFilter(g_nBoxFilterValue,0);

    namedWindow("��ֵ�˲�",1);
    createTrackbar("�ں�ֵ:","��ֵ�˲�",&g_nMeanBlurValue,40,on_MeanBlur);
    on_MeanBlur(g_nMeanBlurValue,0);

    namedWindow("��˹�˲�",1);
    createTrackbar("�ں�ֵ:","��˹�˲�",&g_nGaussianBlurValue,40,on_GaussianBlur);
    on_GaussianBlur(g_nGaussianBlurValue,0);

    println();
    println("\t,������������۲�ͼ��Ч��~");
    println("\t����'q'��ʱ,�����˳�~!");
    

    while(char(waitKey(1)) != 'q');

    return 0;
}

static void on_BoxFilter(int,void*){
    boxFilter(g_srcImg,g_dstImg1,-1,Size(g_nBoxFilterValue+1,g_nBoxFilterValue+1));
    imshow("�����˲�",g_dstImg1);
}
static void on_MeanBlur(int,void*){
    blur(g_srcImg,g_dstImg2,Size(g_nMeanBlurValue+1,g_nMeanBlurValue+1));
    imshow("��ֵ�˲�",g_dstImg2);
}
static void on_GaussianBlur(int,void *){
    GaussianBlur(g_srcImg,g_dstImg3,Size(g_nGaussianBlurValue*2+1,g_nGaussianBlurValue*2+1),0,0);
    imshow("��˹�˲�",g_dstImg3);
}

