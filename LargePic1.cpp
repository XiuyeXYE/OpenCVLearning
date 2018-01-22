#include"OpenCVLib2.hpp"
using  namespace cv;

int main(){

    Mat srcImg = imread("t3.jpg");
    imshow("Origin",srcImg);
    Mat&& dstImg1 = MyLargeTwice(srcImg);
    imshow("My Large Pic1",dstImg1);

    Mat dstImg2;
    //注意OpenCV的resize的参数Size是先列后行!
    resize(srcImg,dstImg2,Size(srcImg.cols*2,srcImg.rows*2));
    imshow("OpenCV Pic1",dstImg2);

    dstImg1 = MyLargeTwice(dstImg1);
    imshow("My Large Pic2",dstImg1);

    Mat dstImg3;
    //注意OpenCV的resize的参数Size是先列后行!
    resize(dstImg2,dstImg3,Size(dstImg2.cols*2,dstImg2.rows*2));
    imshow("OpenCV Pic2",dstImg3);

    waitKey(0);
    return 0;
}
