#include"OpenCVLib2.hpp"
using namespace cv;


int main(){

    Mat img = imread("p1.jpg");
    imshow("Origin",img);

    
    Mat dstImg = Mat::zeros(img.rows,img.cols,img.type());
    
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            
           

            int mid = 5/2;//size 5x5
            int r = i-mid;
            int c = j-mid;
           
            int sumB = 0;
            int sumG = 0;
            int sumR = 0;
           
            for(int x=0;x<5;x++){
               
                for(int y=0;y<5;y++){

                   
                    //dealing of overflow of boundary
                    //eq: overflow region of elements is 0(zero)!(I think)
                    if(r + x < 0 || c + y < 0 ||r+x > img.rows-1 || c+y > img.cols-1){
                        continue;
                    }
                    
                    sumB += img.at<Vec3b>(r+x,c+y)[0];
                    sumG += img.at<Vec3b>(r+x,c+y)[1];
                    sumR += img.at<Vec3b>(r+x,c+y)[2];
                }
            }

            sumB -= img.at<Vec3b>(i,j)[0];
            sumG -= img.at<Vec3b>(i,j)[1];
            sumR -= img.at<Vec3b>(i,j)[2];
            
            dstImg.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(sumB/(5*5-1));
            dstImg.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(sumG/(5*5-1));
            dstImg.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(sumR/(5*5-1));

            

        }
    }

    imshow("Effect",dstImg);
    waitKey(0);
    return 0;
}


