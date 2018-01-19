#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    // double h[3][3] = {
    //     {0.111,0.111,0.111},
    //     {0.111,0.111,0.111},
    //     {0.111,0.111,0.111}
    //     };
    
    // for(int i=0;i<img.rows;i++){
    //     for(int j=0;j<img.cols;j++){
            
    //         for(int k = 0;k<3;k++){
    //             for(int z = 0;z<3;z++){
    //                 if(i+k >= img.rows || z+j >= img.cols){
    //                     continue;
    //                 }
    //                 img.at<Vec3b>(i+k,j+z)[0] = saturate_cast<uchar>(img.at<Vec3b>(i+k,j+z)[0] + img.at<Vec3b>(i+k,j+z)[0]*h[k][z]);
    //                 img.at<Vec3b>(i+k,j+z)[1] = saturate_cast<uchar>(img.at<Vec3b>(i+k,j+z)[0] + img.at<Vec3b>(i+k,j+z)[1]*h[k][z]);
    //                 img.at<Vec3b>(i+k,j+z)[2] = saturate_cast<uchar>(img.at<Vec3b>(i+k,j+z)[0] + img.at<Vec3b>(i+k,j+z)[2]*h[k][z]);
    //             }
                
    //         }

    //     }
    // }
    // imshow("Effect1",img);

    Mat dstImg2 = Mat::zeros(img.rows,img.cols,img.type());
    img = imread("p1.jpg");

    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            
            if(i == 0 || j == 0 || i == img.rows-1 || j == img.cols-1){
                continue;
            }

            int sum = saturate_cast<uchar>(double(img.at<Vec3b>(i-1,j-1)[0] + 
                    img.at<Vec3b>(i-1,j)[0] +
                    img.at<Vec3b>(i-1,j+1)[0] +
                    img.at<Vec3b>(i,j-1)[0] +
                    img.at<Vec3b>(i,j+1)[0] +
                    img.at<Vec3b>(i+1,j-1)[0] +
                    img.at<Vec3b>(i+1,j)[0] +
                    img.at<Vec3b>(i+1,j+1)[0])/8);
            dstImg2.at<Vec3b>(i,j)[0] = sum;

            sum = saturate_cast<uchar>(double(img.at<Vec3b>(i-1,j-1)[1] + 
                    img.at<Vec3b>(i-1,j)[1] +
                    img.at<Vec3b>(i-1,j+1)[1] +
                    img.at<Vec3b>(i,j-1)[1] +
                    img.at<Vec3b>(i,j+1)[1] +
                    img.at<Vec3b>(i+1,j-1)[1] +
                    img.at<Vec3b>(i+1,j)[1] +
                    img.at<Vec3b>(i+1,j+1)[1])/8);
            dstImg2.at<Vec3b>(i,j)[1] = sum;

            sum = saturate_cast<uchar>(double(img.at<Vec3b>(i-1,j-1)[2] + 
                    img.at<Vec3b>(i-1,j)[2] +
                    img.at<Vec3b>(i-1,j+1)[2] +
                    img.at<Vec3b>(i,j-1)[2] +
                    img.at<Vec3b>(i,j+1)[2] +
                    img.at<Vec3b>(i+1,j-1)[2] +
                    img.at<Vec3b>(i+1,j)[2] +
                    img.at<Vec3b>(i+1,j+1)[2])/8);
            dstImg2.at<Vec3b>(i,j)[2] = sum;


        }
    }

    imshow("Effect2",dstImg2);

   

    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<3;j++){
    //         h[i][j] = 0.9;//1/(3*3)
    //     }
    // }
    // Mat dstImg = Mat::zeros(img.rows,img.cols,img.type());
    // // imshow("dstImg",dstImg);
    // img = imread("p1.jpg");
    // for(int i=0;i<img.rows;i++){
    //     for(int j=0;j<img.cols;j++){
            
    //         for(int k = 0;k<3;k++){
    //             for(int z = 0;z<3;z++){
    //                 if(i+k >= img.rows || z+j >= img.cols){
    //                     continue;
    //                 }
    //                 dstImg.at<Vec3b>(i+k,j+z)[0] = saturate_cast<uchar>(img.at<Vec3b>(i+k,j+z)[0] + img.at<Vec3b>(i+k,j+z)[0]*h[k][z]);
    //                 dstImg.at<Vec3b>(i+k,j+z)[1] = saturate_cast<uchar>(img.at<Vec3b>(i+k,j+z)[0] + img.at<Vec3b>(i+k,j+z)[1]*h[k][z]);
    //                 dstImg.at<Vec3b>(i+k,j+z)[2] = saturate_cast<uchar>(img.at<Vec3b>(i+k,j+z)[0] + img.at<Vec3b>(i+k,j+z)[2]*h[k][z]);
    //             }
                
    //         }

    //     }
    // }
    // imshow("Effect3",dstImg);
    
    waitKey(0);

    return 0;
}
