#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat srcImg = imread("t3.jpg");
    
    imshow("Origin",srcImg);
    

    int rows = srcImg.rows*2;
    int cols = srcImg.cols*2;
   
    Mat dstImg(rows,cols,srcImg.type());
    //In fact,first line begins from zero.
    for(int i=0;i<srcImg.rows;i++){
        for(int j=0;j<srcImg.cols;j++){
            dstImg.at<Vec3b>(2*i,2*j)[0] = srcImg.at<Vec3b>(i,j)[0];
            dstImg.at<Vec3b>(2*i,2*j)[1] = srcImg.at<Vec3b>(i,j)[1];
            dstImg.at<Vec3b>(2*i,2*j)[2] = srcImg.at<Vec3b>(i,j)[2];
        }
    }

    imshow("Odd Line Effect",dstImg);

    Mat dstImg1 = MyMeanFilter(dstImg,7);

    imshow("Larging Pic1",dstImg1);

    Mat dstImg2;
    bilateralFilter(dstImg,dstImg2,25,25*2,25/2);
    imshow("Larging Pic2",dstImg2);

    Mat dstImg3(dstImg.rows,dstImg.cols,dstImg.type(),Scalar::all(0));

    int oddNum = 3;//5x5 7x7 9x9 效果差

    for(int i=0;i<dstImg.rows;i++){
        for(int j=0;j<dstImg.cols;j++){
            
            int mid = oddNum/2;
            int r = i-mid;
            int c = j-mid;
           
            int sumB = 0;
            int sumG = 0;
            int sumR = 0;
            //不为0的像素点个数
            int notZeroItemNum = 0;

            for(int x=0;x<oddNum;x++){
                for(int y=0;y<oddNum;y++){
                  
                    //dealing of overflow of boundary
                    //eq: overflow region of elements is 0(zero)!(I think)
                    if(r + x < 0 || c + y < 0 ||r+x > dstImg.rows-1 || c+y > dstImg.cols-1){
                        continue;
                    }

                    //typedef Vec<uchar, 3> cv::Vec3b
                    int blueValue = dstImg.at<Vec3b>(r+x,c+y)[0];
                    int greenValue = dstImg.at<Vec3b>(r+x,c+y)[1];
                    int redValue = dstImg.at<Vec3b>(r+x,c+y)[2];
                    if( blueValue != 0 || greenValue != 0 || redValue != 0){
                        sumB += blueValue;
                        sumG += greenValue;
                        sumR += redValue;
                        notZeroItemNum ++;
                    }
                   
                }
            }
            //必须要判断notZeroItemNum为0的情况,否则有除以0的运行时错误(因为图像中有可能是一大片黑的(值为0))
            if(notZeroItemNum != 0){
                dstImg3.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(sumB/notZeroItemNum);
                dstImg3.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(sumG/notZeroItemNum);
                dstImg3.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(sumR/notZeroItemNum);
            }
            
        }
    }

    imshow("Larging Pic3",dstImg3);    

    Mat dstImg4;
    resize(srcImg,dstImg4,dstImg.size());
    imshow("Larging Pic4",dstImg4);   

    waitKey(0);
    return 0;
}