#include"OpenCVLib2.hpp"
using namespace cv;

Mat g_srcImg,g_dstImg;
int g_nElementShape = MORPH_RECT;
int g_nMaxIterationNum = 10;
int g_nOpenCloseNum = 0;
int g_nErodeDilateNum = 0;
int g_nTopBlackHatNum = 0;

static void on_OpenClose(int,void*);
static void on_ErodeDilate(int,void*);
static void on_TopBlackHat(int,void*);



int main(){
    g_srcImg = imread("p1.jpg");

    if(!g_srcImg.data){
        println("��ȡsrcImgʧ��!");
        return -1;
    }
    
    imshow("Origin",g_srcImg);

    namedWindow("��/������",WINDOW_AUTOSIZE);
    namedWindow("��ʴ/����",WINDOW_AUTOSIZE);
    namedWindow("��ñ/��ñ",WINDOW_AUTOSIZE);

    g_nOpenCloseNum = 9;
    g_nErodeDilateNum = 9;
    g_nTopBlackHatNum = 2;

    createTrackbar("����ֵ","��/������",&g_nOpenCloseNum,g_nMaxIterationNum*2+1,on_OpenClose);
    createTrackbar("����ֵ","��ʴ/����",&g_nErodeDilateNum,g_nMaxIterationNum*2+1,on_ErodeDilate);
    createTrackbar("����ֵ","��ñ/��ñ",&g_nTopBlackHatNum,g_nMaxIterationNum*2+1,on_TopBlackHat);
    
    while(true){

        int c;
        on_OpenClose(g_nOpenCloseNum,0);
        on_ErodeDilate(g_nErodeDilateNum,0);
        on_TopBlackHat(g_nTopBlackHatNum,0);

        c = waitKey(0);

        if(char(c) == 'q' || c == 27 ){
            break;
        }

        if(char(c) == '1'){
            g_nElementShape = MORPH_ELLIPSE;
        }
        else if(char(c) == '2'){
            g_nElementShape = MORPH_RECT;
        }
        else if(char(c) == '3'){
            g_nElementShape = MORPH_CROSS;
        }
        else if(char(c) == ' '){
            g_nElementShape = (g_nElementShape+1)%3;
        }

    }
    
    return 0;
}
static void on_OpenClose(int ,void *){
    int offset = g_nOpenCloseNum - g_nMaxIterationNum;
    int absolute_offset = offset > 0 ? offset : -offset;
    Mat element = getStructuringElement(g_nElementShape,Size(absolute_offset*2+1,absolute_offset*2+1),Point(absolute_offset,absolute_offset));
    if(offset < 0){
        morphologyEx(g_srcImg,g_dstImg,MORPH_OPEN,element);
    }
    else{
        morphologyEx(g_srcImg,g_dstImg,MORPH_CLOSE,element);
    }
    imshow("��/������",g_dstImg);
}
static void on_ErodeDilate(int ,void *){
    int offset = g_nErodeDilateNum - g_nMaxIterationNum;
    int absolute_offset = offset > 0 ? offset : -offset;
    Mat element = getStructuringElement(g_nElementShape,Size(absolute_offset*2+1,absolute_offset*2+1),Point(absolute_offset,absolute_offset));
    if(offset < 0){
        erode(g_srcImg,g_dstImg,element);
    }
    else{
        dilate(g_srcImg,g_dstImg,element);
    }
    imshow("��ʴ/����",g_dstImg);
}

static void on_TopBlackHat(int,void*){
    int offset = g_nTopBlackHatNum - g_nMaxIterationNum;
    int absolute_offset = offset > 0 ? offset : -offset;
    Mat element = getStructuringElement(g_nElementShape,Size(absolute_offset*2+1,absolute_offset*2+1),Point(absolute_offset,absolute_offset));
    println(absolute_offset);
    if(offset < 0){
        morphologyEx(g_srcImg,g_dstImg,MORPH_TOPHAT,element);
    }
    else{
        morphologyEx(g_srcImg,g_dstImg,MORPH_BLACKHAT,element);
    }
    imshow("��ñ/��ñ",g_dstImg);
}
