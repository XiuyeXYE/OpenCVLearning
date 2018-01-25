#include"OpenCVLib2.hpp"
using namespace cv;
int main(){

    Mat src = imread("a1.jpg");
    Mat midImg,dstImg;

    Canny(src,midImg,50,200,3);
    cvtColor(midImg,dstImg,CV_GRAY2BGR);


    vector<Vec2f> lines;
    HoughLines(midImg,lines,1,CV_PI/180,150,0,0);

    for(size_t i=0;i<lines.size();i++){
        float rho = lines[i][0],theta = lines[i][1];
        Point pt1,pt2;
        double a = cos(theta),b = sin(theta);
        double x0 = a*rho,y0 = b*rho;
        pt1.x = cvRound(x0+1000*(-b));
        pt1.y = cvRound(y0+1000*(a));
        pt2.x = cvRound(x0-1000*(-b));
        pt2.x = cvRound(y0-1000*(a));
        line(dstImg,pt1,pt2,Scalar(55,100,195),1,CV_AA);
    }
    imshow("Origin",src);
    imshow("midImg",midImg);
    imshow("Effect",dstImg);

    waitKey(0);
    return 0;
}