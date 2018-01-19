#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat srcImg = imread("p1.jpg");
    Mat imgBlueChannel,imgGreenChannel,imgRedChannel,mergeImg;

    vector<Mat> channels;
    split(srcImg,channels);

    imgBlueChannel = channels[0];
    imgGreenChannel = channels[1];
    imgRedChannel = channels[2];

    imshow("Blue",imgBlueChannel);
    imshow("Green",imgGreenChannel);
    imshow("Red",imgRedChannel);

    merge(channels,mergeImg);

    imshow("Merge Img",mergeImg);

    waitKey(0);


    return 0;
}