#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat m = imread("t3.jpg");

    println("Img Depth: ",m.depth());

    return 0;
}