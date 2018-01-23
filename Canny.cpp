#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg");
    imshow("origin",src);

    Mat out;
    //彩色图中有更多的细节边缘
    Canny(src,out,3,9,3);
    imshow("Out1",out);

    //to Gray
    Mat gray;
    cvtColor(src,gray,COLOR_RGB2GRAY);
    
    Canny(gray,out,3,9,3);
    imshow("Out4",out);//边缘细节丢失

    //降噪
    Mat edge;
    blur(gray,edge,Size(3,3));
    //运行canny算子
    Canny(edge,out,3,9,3);
    
    imshow("out2",out);

    Mat dst(Scalar::all(0));

    src.copyTo(dst,out);
    imshow("out3",dst);

    Mat t3 = imread("t3.jpg",IMREAD_GRAYSCALE);
    Mat t2 = imread("t2.jpg",IMREAD_GRAYSCALE);

    Mat t(Scalar::all(0));

    t2.copyTo(t,t3);
    imshow("t2",t2);
    imshow("t3",t3);
    imshow("t",t);

    waitKey(0);
    return 0;
}