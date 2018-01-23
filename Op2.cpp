#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat src = imread("p1.jpg");
    println(src.type());
    
    Mat out(src.rows,src.cols,src.type(),Scalar::all(0));

    for(int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){
            int b = src.at<Vec3b>(i,j)[0];
            if(b > 100 && b < 150){
                out.at<Vec3b>(i,j)[0] = 0;
            }

            int g = src.at<Vec3b>(i,j)[1];
            if(g > 100 && g < 150){
                out.at<Vec3b>(i,j)[1] = 0;
            }

            int r = src.at<Vec3b>(i,j)[2];
            if(r > 100 && r < 150){
                out.at<Vec3b>(i,j)[2] = 255;
            }
        }
    }
    println("OK");
    imshow("Out",out);

    waitKey(0);//这句很重要不要忘了!

    return 0;
}