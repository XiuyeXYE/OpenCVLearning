

#ifndef __MY_BLUR_H
#define __MY_BLUR_H
//û����Ӧusing namespace ����Ҫ����cv,������뱨��!
//ͷ�ļ��ĺ�������������cpp�ļ��Ķ��������ͬ,�������ӵ�ʱ�򱨴�.
//��ʹ����ͨ�����ӵ�ʱ��ҲҪ����!
cv::Mat MyMeanFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyDilateFilter(const cv::Mat& inputMat,int oddNum);
cv::Mat MyErodeFilter(const cv::Mat& inputMat,int oddNum);

#endif