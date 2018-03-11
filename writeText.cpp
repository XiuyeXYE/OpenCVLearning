#include"OpenCVLib2.hpp"
using namespace cv;
using namespace std;

int main(){

    Mat img = imread("C:/Users/Administrator/Desktop/123.jpg");
    string text = "XiuYe";
    int baseline = 0;
    Size s = getTextSize(text,FONT_HERSHEY_COMPLEX,2,2,&baseline);
    Point origin;
    origin.x = img.cols/2 - s.width/2;
    origin.y = img.rows/2 - s.height/2;
    putText(img,text,origin,FONT_HERSHEY_COMPLEX,2,Scalar(0,255,255),2,8,0);

    imshow("img",img);
    imwrite("C:/Users/Administrator/Desktop/123_out.jpg",img);
    waitKey(0);
    return 0;
}
