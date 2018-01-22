

#ifndef __MY_BLUR_H
#define __MY_BLUR_H
//没有适应using namespace 所以要加上cv,否则编译报错!
//头文件的函数声明必须与cpp文件的定义参数相同,否则连接的时候报错.
//即使编译通过连接的时候也要报错!
cv::Mat MyMeanFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyDilateFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyErodeFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyOpenFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyCloseFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyTopHatFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyBlackHatFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyMorphologicalGradientFilter(const cv::Mat& inputMat,int oddNum);

#endif