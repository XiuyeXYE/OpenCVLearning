#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    vector<Mat> channels;
    Mat imgBlueChannel;
    Mat imgGreenChannel;
    Mat imgRedChannel;

    //OpenCV的通道是BGR 不是 RGB,顺序要注意
    Mat srcImg = imread("p1.jpg");

    split(srcImg,channels);

    imgBlueChannel = channels.at(0);
    imgGreenChannel = channels.at(1);
    imgRedChannel = channels.at(2);

    imshow("Blue",imgBlueChannel);
    imshow("Green",imgGreenChannel);
    imshow("Red",imgRedChannel);


    waitKey(0);


    return 0;
}

