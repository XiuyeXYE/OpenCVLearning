#include"OpenCVLib.hpp"
using namespace cv;

/**
 * First Implementation
 * 
 */
void colorReduce(Mat &inputImage,Mat& outputImage,int div){

    outputImage = inputImage.clone();
    int rowNumber = outputImage.rows;
    int colNumber = outputImage.cols * outputImage.channels();

    for(int i=0;i<rowNumber;i++){
        uchar *data = outputImage.ptr<uchar>(i);
        for(int j=0;j<colNumber;j++){
            data[j] = data[j]/div*div+div/2;
            // println(data[j]);
        }
    }
}



int main(){

    Mat srcImg = imread("monkeyKing.jpg");
    imshow("SRC IMG",srcImg);
    Mat dstImg;
    dstImg.create(srcImg.rows,srcImg.cols,srcImg.type());
    double t0 = static_cast<double>(getTickCount());
    colorReduce(srcImg,dstImg,32);//需要实现
    t0 = ((double)getTickCount()-t0)/getTickFrequency();
    
    println("此方法运行时间为: ");
    println(t0,"s");
    //此文件是utf-8编码,以下编译输出是乱码(windows 中文)
    // println("此方法运行时间为: ",t0,"秒");

    imshow("DEST IMG",dstImg);
    waitKey(0);
    return 0;
}