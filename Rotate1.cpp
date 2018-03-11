#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    /**
     * [
     *  cosA -sinA
     *  sinA cosA
     * ]
     * 
     * A = pi/2 (90)
     * [
     *  0 -1
     *  1 0
     * ]
     * 正方向旋转90度.
     * 图像的坐标为左上角(0,0)右下角(cols,rows)
     * 向右为x正方向,向下为y正方向,
     * 所以正方向旋转90度为向下旋转90度
     */ 

    int a[2][2] = {0,-1,1,0};

    Mat src = imread("logo.png");
    imshow("Origin",src);
    
    Mat dst(src.cols,src.rows,src.type());


    println("src.rows = ",src.rows," ; src.cols = ",src.cols);
    println("dst.rows = ",dst.rows," ; dst.cols = ",dst.cols);


    for(int i=0;i<src.cols;i++){
        for(int j=0;j<src.rows;j++){
            int x = dst.cols + a[0][0]*i + a[0][1]*j - 1;/* dst.cols - j - 1; */
            int y = a[1][0]*i + a[1][1]*j;/* i; */
            // println("x = ",x," ; y = ",y);
           
            // println("dst rows = ",dst.rows," ; i = ",i);
            // println("j = ",j);

            // println("src(",src.rows,",",src.cols,"),i = ",i," ; j = ",j);

            // println("dst(",dst.rows,",",dst.cols,")");
            

            //at(row,col)
            // <=> at(y,x) (in pic row => y,col => x)
            dst.at<Vec3b>(y,x)[0] = src.at<Vec3b>(j,i)[0];
            dst.at<Vec3b>(y,x)[1] = src.at<Vec3b>(j,i)[1];
            dst.at<Vec3b>(y,x)[2] = src.at<Vec3b>(j,i)[2];
            // println("x = ",x," ; y = ",y);
        }
    }

    // println("Over");
    imshow("Effect",dst);

    waitKey(0);
    return 0;
}
