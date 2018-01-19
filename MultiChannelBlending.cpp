#include"OpenCVLib2.hpp"

using namespace cv;


int main(){

    println("OpenCV版本号:",CV_VERSION);

    Mat srcImg;
    Mat logoImg;
    vector<Mat> channels;
    

    srcImg = imread("p1.jpg");
    //必须为单通道灰度图,否则默认为BGR3通道图,下面的addWeighted操作会报错.
    logoImg = imread("t3.jpg",IMREAD_GRAYSCALE);

    if(!srcImg.data){
        println("读取srcImg失败~!");
        return -1;
    }
    if(!logoImg.data){
        println("读取logoImg失败~!");
        return -1;
    }

    split(srcImg,channels);

    Mat imgBlueChannel = channels[0];
    Mat imgBlueChannelROI= imgBlueChannel(Rect(100,100,logoImg.cols,logoImg.rows));
    addWeighted(imgBlueChannelROI,1.0,logoImg,0.5,0,imgBlueChannelROI);

    merge(channels,srcImg);

   
    
    
   
    
    

    

    Mat imgGreenChannel = channels[1];

    Mat imgGreenChannelROI = imgGreenChannel(Rect(300,100,logoImg.cols,logoImg.rows));

    addWeighted(imgGreenChannelROI,1.0,logoImg,0.5,0,imgGreenChannelROI);

    merge(channels,srcImg);


    Mat imgRedChannel = channels[2];

    Mat imgRedChannelROI = imgRedChannel(Rect(500,100,logoImg.cols,logoImg.rows));

    addWeighted(imgRedChannelROI,1.0,logoImg,0.5,0,imgRedChannelROI);

    merge(channels,srcImg);


    imshow("原图+logo BGR通道",srcImg);
    

    waitKey(0);
    return 0;
}

