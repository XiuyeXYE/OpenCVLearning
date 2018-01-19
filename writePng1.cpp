#include"OpenCVLib.hpp"
#include<vector>
// #pragma setlocale(".65001")
#pragma execution_character_set("utf-8")
using namespace std;
using namespace cv;

void createAlphaMat(Mat &mat){
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
            Vec4b &rgba = mat.at<Vec4b>(i,j);//get someone pixel information
            rgba[0] = UCHAR_MAX;//255
            rgba[1] = saturate_cast<uchar>((float (mat.cols-j))/((float)mat.cols)*UCHAR_MAX);//resemble ((n-i)/n)*255
            rgba[2] = saturate_cast<uchar>((float (mat.rows-i))/((float)mat.rows)*UCHAR_MAX);//resemble ((n-i)/n)*255
            rgba[3] = saturate_cast<uchar>(0.5*(rgba[1]+rgba[2]));//  255*255/2 ~ 0
        }
    }
}

int main(){
    
    Mat mat(480,640,CV_8UC4);
    createAlphaMat(mat);
    vector<int> compression_params;
    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    cout << "UCHAR_MAX = " << UCHAR_MAX << endl;

    try{
        imwrite("透明的Alpha值图.png",mat,compression_params);
        imshow("generating png pic",mat);
        
        cout << "The pic flush over! You can see current path of this project!" << endl;

        waitKey(0);

    }
    catch(runtime_error& err){
        cerr << "translation error!" << err.what() << endl;
        return 1;
    }
    return 0;


}

