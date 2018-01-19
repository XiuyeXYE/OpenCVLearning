#include"OpenCVLib.hpp"
using namespace cv;

int main(){

    Mat m1 = imread("p1.jpg");
    namedWindow("m1");
    imshow("m1",m1);

    Mat m2 = imread("t3.jpg");
    namedWindow("m2");
    imshow("m2",m2);

    // Mat m3 = imread("p2.jpg");
    // namedWindow("m3");
    // imshow("m3",m3);

    //Mat imgROI = m1(Rect(0,0,m2.cols,m2.rows));
    
    //imgROI = image(Range(350,350+m1.rows),Range(800,800+m1.cols));
    // addWeighted(imgROI,0.5,m2,0.3,0.2,imgROI);
    // addWeighted(imgROI,1.0,m2,0.3,0.2,imgROI);
    // addWeighted(imgROI,0,m2,0.3,0.2,imgROI);
    
    // imgROI = m1(Rect(m2.cols,0,m2.cols,m2.rows));
    // addWeighted(imgROI,0.6,m2,0.3,0.2,imgROI);
    Mat imgROI;
    int col_length = m1.cols/m2.cols;
    int row_height = m1.rows/m2.rows;
    int result = 0;
    bool bf = true;
    for(int i=0;i<row_height&&bf;i++){
       
        for(int j=0;j<col_length&&bf;j++){
            result = j+i*row_height;
            if(result > 10){
                // goto end;    
                bf = false;
            }
            imgROI = m1(Rect(m2.cols*j,m2.rows*i,m2.cols,m2.rows));
            addWeighted(imgROI,0.1*result,m2,0.3,0.2,imgROI);
            
        }
       
        
    }
    // end:

    namedWindow("mixed");
    imshow("mixed",m1);


    waitKey(0);

}
