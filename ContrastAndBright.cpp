#include"OpenCVLib2.hpp"
using namespace cv;

static void on_ContrastAndBright(int,void *);
static void ShowHelpText();

int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImg,g_dstImg;
/**
 * ͼ��Աȶ�,����
 * 
 * Formula:
 *      g(x) = a*f(x) + b
 * ������ʵ���о���ͼƬ������
 * g(i,j) = a*f(i,j) + b
 * ���ز��ǵ�ͨ��,ÿ��ͨ���������Ϲ�ʽ. 
 * 
 * a--һ�����ͼ��ĶԱȶ�;
 * b--һ�����ͼ�������.
 * 
 */ 
int main(){
    g_srcImg = imread("p1.jpg");
    if(!g_srcImg.data){
        println("��ȡg_srcImgͼƬʧ��!");
        return -1;
    }

    imshow("ԭʼͼ����",g_srcImg);

    g_dstImg = Mat::zeros(g_srcImg.size(),g_srcImg.type());

    g_nContrastValue = 80;
    g_nBrightValue = 80;
    namedWindow("Ч��ͼ����",1);
    //����:tracker name,�����Ĵ���name,�󶨵ı���,tracker���ֵ,�¼��ص�����
    createTrackbar("�Աȶ�:","Ч��ͼ����",&g_nContrastValue,300,on_ContrastAndBright);
    createTrackbar("����:","Ч��ͼ����",&g_nBrightValue,200,on_ContrastAndBright);
    //���¼�������ʼ������
    on_ContrastAndBright(g_nContrastValue,0);
    on_ContrastAndBright(g_nBrightValue,0);

    waitKey(0);

    return 0;

}

static void on_ContrastAndBright(int,void *){

   
    for(int y=0;y<g_srcImg.rows;y++){
        for(int x=0;x<g_srcImg.cols;x++){
            for(int i=0;i<3;i++){
                g_dstImg.at<Vec3b>(y,x)[i] = /*saturate_cast��ֹ����overflow*/
                saturate_cast<uchar>((g_nContrastValue*0.01)*g_srcImg.at<Vec3b>(y,x)[i]+g_nBrightValue);
                
            }
        }
    }
    
    imshow("Ч��ͼ����",g_dstImg);

}
