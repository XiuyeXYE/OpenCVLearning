
#ifndef __TRANSFORMATION_H
#define __TRANSFORMATION_H


cv::Mat MySmallTwice(const cv::Mat& srcImg);
cv::Mat MyLargeTwice(const cv::Mat& srcImg,int oddNum=3);//5x5 7x7 9x9 Ð§¹û²î
cv::Mat MyRGB2Gray(const cv::Mat& srcImg);

#endif