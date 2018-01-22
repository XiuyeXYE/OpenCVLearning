#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    println(static_cast<int>(saturate_cast<uchar>(600)));
    println(static_cast<int>(saturate_cast<uchar>(100)));
    return 0;
}