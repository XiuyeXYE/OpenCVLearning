#include"OpenCVLib2.hpp"
using namespace cv;

int main(){


    Mat src = imread("p1.jpg");
    imshow("Origin",src);

    Mat dst(src.rows,src.cols,CV_8UC1,Scalar::all(0));
    
    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){

            int b = src.at<Vec3b>(i,j)[0];
            int g = src.at<Vec3b>(i,j)[1];
            int r = src.at<Vec3b>(i,j)[2];
            
            //int gray = (b*11+g*59+r*30)/100
            int gray = b*0.11 + g*0.59 + r*0.3;

            dst.at<uchar>(i,j) = saturate_cast<uchar>(gray);

        }
    }


    imshow("Destination1",dst);

    Mat dst2(src.rows,src.cols,CV_8UC1,Scalar::all(0));
    
    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){

            int b = src.at<Vec3b>(i,j)[0];
            int g = src.at<Vec3b>(i,j)[1];
            int r = src.at<Vec3b>(i,j)[2];
            
            int gray = (b*28 + g*151 + r*76)>>8;
            
            dst2.at<uchar>(i,j) = saturate_cast<uchar>(gray);

        }
    }

    imshow("Destination2",dst2);

    Mat dst3(src.rows,src.cols,CV_8UC1,Scalar::all(0));
    
    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){

            int b = src.at<Vec3b>(i,j)[0];
            int g = src.at<Vec3b>(i,j)[1];
            int r = src.at<Vec3b>(i,j)[2];
            
            int gray = (b + g + r)/3;
            
            dst3.at<uchar>(i,j) = saturate_cast<uchar>(gray);

        }
    }

    imshow("Destination3",dst3);


    Mat dst4 = MyRGB2Gray(src);
    imshow("Gray img",dst4);

    waitKey(0);
    return 0;
}
