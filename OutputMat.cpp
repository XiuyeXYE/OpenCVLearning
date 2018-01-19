#include"OpenCVLib.hpp"
using namespace cv;

void outMat(Mat &mat){
    std::cout << mat << std::endl;
}

int main(){
    Mat m(2,2,CV_8UC3,Scalar(0,0,255));
    std::cout << "M= " << std::endl << " " << m << std::endl << std::endl;
    int sz[3] = {2,2,2};
    // Mat L(3,sz,CV_8UC /*error*/,Scalar::all(0));
    // outMat(L);
    m.create(4,4,CV_8UC(2));
    outMat(m);
    Mat E = Mat::eye(4,4,CV_64F);
    outMat(E);

    Mat one = Mat::ones(2,2,CV_32F);
    outMat(one);

    Mat O = Mat::zeros(3,3,CV_8UC1);
    outMat(O);

    Mat C = (Mat_<double>(3,3)<<1,2,3,4,5,6,7,8,9);
    outMat(C);

    Mat row = C.row(0).clone();
    outMat(row);

    Mat r = Mat(10,3,CV_8UC3);
    randu(r,Scalar::all(0),Scalar::all(255));
    outMat(r);

    return 0;
}
