/**
 * 解决乱码:
 * 在windows 中文 and vs2013 编译器
 * 需要设置"文件"编码为 UNICODE 或者 GBK 
 * 否则将输出乱码,某些时候还会编译错误!
 * 具体"本质"原因不清楚
 * 
 * 
 */ 

#include"OpenCVLib2.hpp"
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

/**
 * Second Implementation
 * 
 */ 
void colorReduce2(Mat &inputImage,Mat& outputImage,int div){

    outputImage = inputImage.clone();

    Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
    Mat_<Vec3b>::iterator end = outputImage.end<Vec3b>();

    for(;it!=end;it++){
        (*it)[0] = (*it)[0]/div*div + div/2;
        (*it)[1] = (*it)[1]/div*div + div/2;
        (*it)[2] = (*it)[2]/div*div + div/2;
        
    }
}

/**
 * Third Implementation
 * 
 */ 
void colorReduce3(Mat &inputImage,Mat& outputImage,int div){

    outputImage = inputImage.clone();

    int rowNumber = outputImage.rows;
    int colNumber = outputImage.cols;

    for(int i=0;i<rowNumber;i++){
        uchar *data = outputImage.ptr<uchar>(i);
        for(int j=0;j<colNumber;j++){
            outputImage.at<Vec3b>(i,j)[0] = outputImage.at<Vec3b>(i,j)[0]/div*div+ div/2;
            outputImage.at<Vec3b>(i,j)[1] = outputImage.at<Vec3b>(i,j)[1]/div*div+ div/2;
            outputImage.at<Vec3b>(i,j)[2] = outputImage.at<Vec3b>(i,j)[2]/div*div+ div/2;
        }
    }
}


int main(){

    Mat srcImg = imread("p1.jpg");
    imshow("SRC IMG",srcImg);

    Mat dstImg;
    dstImg.create(srcImg.rows,srcImg.cols,srcImg.type());

    double t0 = static_cast<double>(getTickCount());
    colorReduce(srcImg,dstImg,32);//需要实现
    t0 = ((double)getTickCount()-t0)/getTickFrequency();    
    println("colorReduce 方法运行时间为: ",t0," 秒");
    imshow("DEST IMG 1",dstImg);

    double t1 = static_cast<double>(getTickCount());
    colorReduce2(srcImg,dstImg,32);//需要实现
    t1 = ((double)getTickCount()-t1)/getTickFrequency();    
    println("colorReduce2 方法运行时间为: ",t1," 秒");
    imshow("DEST IMG 2",dstImg);

    double t2 = static_cast<double>(getTickCount());
    colorReduce3(srcImg,dstImg,32);//需要实现
    t2 = ((double)getTickCount()-t2)/getTickFrequency();    
    println("colorReduce3 方法运行时间为: ",t2," 秒");
    imshow("DEST IMG 3",dstImg);

    // println("输出矩阵为: ",dstImg);//it's too much!

    waitKey(0);
    return 0;
}