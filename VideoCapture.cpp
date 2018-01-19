#include"OpenCVLib.hpp"
using namespace cv;

int main(){

    VideoCapture capture("test.avi");
    //capture.open("test.avi");
    while(true){

        Mat frame;
        capture >> frame;
        if(frame.empty()){
            break;
        }
        imshow("Show Frame:",frame);
        waitKey(30);

    }
    return 0;
}