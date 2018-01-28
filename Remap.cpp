#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg");
    if(!src.data){
        println("Read Pic failure!");
        return -1;
    }
    imshow("Origin",src);

    Mat dst(src.size(),src.type()) ;
    Mat map_x(src.size(),CV_32FC1);
    Mat map_y(src.size(),CV_32FC1); 

    for(int j=0;j<src.rows;j++){
        for(int i=0;i<src.cols;i++){
            map_x.at<float>(j,i) = static_cast<float>(src.cols - i);
            map_y.at<float>(j,i) = static_cast<float>(src.rows - j);
        }

    }
    remap(src,dst,map_x,map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
    imshow("Effect",dst);
    
    waitKey(0);
    return 0;
}