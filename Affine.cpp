#include"OpenCVLib2.hpp"
using namespace cv;

#define ORIGIN_WINDOW_NAME "Origin"
#define WARP_WINDOW_NAME "Wrap"
#define WARP_ROTATE_WINDOW_NAME "Warp and Rotate"

int main(){

    Point2f srcTriangle[3];
    Point2f dstTriangle[3];

    Mat rotMat(2,3,CV_32FC1);
    Mat warpMat(2,3,CV_32FC1);

    Mat src,dst_warp,dst_warp_rotate;

    src = imread("p1.jpg");
    if(!src.data){
        println("read error!");
        return -1;
    }

    imshow(ORIGIN_WINDOW_NAME,src);

    dst_warp = Mat::zeros(src.rows,src.cols,src.type());

    srcTriangle[0] = Point2f(0,0);
    srcTriangle[1] = Point2f(static_cast<float>(src.cols-1),0);
    srcTriangle[2] = Point2f(0,static_cast<float>(src.rows-1));
    
    dstTriangle[0] = Point2f(static_cast<float>(src.cols*0.0),static_cast<float>(src.rows*0.33));
    dstTriangle[1] = Point2f(static_cast<float>(src.cols*0.65),static_cast<float>(src.rows*0.35));
    dstTriangle[2] = Point2f(static_cast<float>(src.cols*0.15),static_cast<float>(src.rows*0.6));
    
    for(int i=0;i<3;i++){
        println("srcTriangle[",i,"] = ",srcTriangle[i]);
    }
    for(int i=0;i<3;i++){
        println("dstTriangle[",i,"] = ",dstTriangle[i]);
    }

    warpMat = getAffineTransform(srcTriangle,dstTriangle);

    //println("warpMat = ",warpMat);//output error

    warpAffine(src,dst_warp,warpMat,dst_warp.size());

    imshow(WARP_WINDOW_NAME,dst_warp);

    Point center = Point(dst_warp.cols/2,dst_warp.rows/2);

    double angle = -30.0;
    double scale = 0.8;

    rotMat = getRotationMatrix2D(center,angle,scale);

    warpAffine(dst_warp,dst_warp_rotate,rotMat,dst_warp.size());

    imshow(WARP_ROTATE_WINDOW_NAME,dst_warp_rotate);

    waitKey(0);
    return 0;
}   