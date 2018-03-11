#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg");
    imshow("Origin",src);
    Mat dst(src.rows,src.cols,src.type());

    int dx = 100;
    int dy = 100;
    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){

            int x = j + dx;
            int y = i + dy;
            if(x > src.cols - 1 || y > src.rows - 1){
                continue;
            }
            dst.at<Vec3b>(y,x)[0] = src.at<Vec3b>(i,j)[0];
            dst.at<Vec3b>(y,x)[1] = src.at<Vec3b>(i,j)[1];
            dst.at<Vec3b>(y,x)[2] = src.at<Vec3b>(i,j)[2];

        }

    }
    
    imshow("Effect",dst);

    dst = MyTranslation(src,100,100);

    imshow("Effect2",dst);


    dst = MyTranslation(src,-100,-100);

    imshow("Effect3",dst);

    double a = 0.3;
    double b = 0.5;
    dst = Mat::zeros(src.rows,src.cols,src.type());
    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){
            int x = a*j - b*i + src.cols/2;
            
            int y = b*j + a*i;
           
            if(x < 0 || y < 0 || x > src.cols - 1 || y > src.rows - 1){
                continue;
            }
            // println(x,",",y);

            dst.at<Vec3b>(y,x)[0] = src.at<Vec3b>(i,j)[0];
            dst.at<Vec3b>(y,x)[1] = src.at<Vec3b>(i,j)[1];
            dst.at<Vec3b>(y,x)[2] = src.at<Vec3b>(i,j)[2];
        }
    }
    imshow("Effect4",dst);

    waitKey(0);
    return 0;
}
