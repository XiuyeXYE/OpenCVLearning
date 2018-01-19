#include"OpenCVLib.hpp"
#include<iostream>
using namespace cv;

int  main(){

    VideoCapture capture(0);//摄像头
    if(!capture.isOpened()){
        std::cout << "cannot open camera" << std::endl;
        return -1;
    }
    
    try{
        while(true){
        Mat frame;
        capture >> frame;
        imshow("Camera",frame);

        if(frame.empty()){
            break;
        }

        waitKey(30);


        }
    }
    catch(Exception& e){
        std::cout << "exception msg : " << e.what() << std::endl;
    }
    
    

    return 0;
}

