#include<opencv2/core/core.hpp>
#include"MyBlur.hpp"
#include"MyMath.hpp"

using namespace cv;

Mat MyMeanFilter(const Mat& inputMat,int oddNum){

    Mat dstImg(inputMat.rows,inputMat.cols,inputMat.type(),Scalar::all(0));
    
    for(int i=0;i<inputMat.rows;i++){
        for(int j=0;j<inputMat.cols;j++){
            
          
            int mid = oddNum/2;//size 5x5
            int r = i-mid;
            int c = j-mid;
           
            int sumB = 0;
            int sumG = 0;
            int sumR = 0;
           
            for(int x=0;x<oddNum;x++){
               
                for(int y=0;y<oddNum;y++){

                   
                    //dealing of overflow of boundary
                    //eq: overflow region of elements is 0(zero)!(I think)
                    if(r + x < 0 || c + y < 0 ||r+x > inputMat.rows-1 || c+y > inputMat.cols-1){
                        continue;
                    }
                    
                    sumB += inputMat.at<Vec3b>(r+x,c+y)[0];
                    sumG += inputMat.at<Vec3b>(r+x,c+y)[1];
                    sumR += inputMat.at<Vec3b>(r+x,c+y)[2];
                }
            }

            sumB -= inputMat.at<Vec3b>(i,j)[0];
            sumG -= inputMat.at<Vec3b>(i,j)[1];
            sumR -= inputMat.at<Vec3b>(i,j)[2];
            int dividend = oddNum * oddNum - 1;
            dstImg.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(sumB/dividend);
            dstImg.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(sumG/dividend);
            dstImg.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(sumR/dividend);

            

        }
    }
    return dstImg;
}


Mat MyDilateFilter(const Mat& inputMat,int oddNum){

  
    Mat dstImg(inputMat.rows,inputMat.cols,inputMat.type(),Scalar::all(0));
    
    for(int i=0;i<inputMat.rows;i++){
        for(int j=0;j<inputMat.cols;j++){
         
            int mid = oddNum/2;//size 5x5
            int r = i-mid;
            int c = j-mid;
           
            uchar maxB = 0;
            uchar maxG = 0;
            uchar maxR = 0;
           
            for(int x=0;x<oddNum;x++){
               
                for(int y=0;y<oddNum;y++){

                   
                    //dealing of overflow of boundary
                    //eq: overflow region of elements is 0(zero)!(I think)
                    if(r + x < 0 || c + y < 0 ||r+x > inputMat.rows-1 || c+y > inputMat.cols-1){
                        continue;
                    }
                    
                    maxB = xy_max(maxB,inputMat.at<Vec3b>(r+x,c+y)[0]);
                    maxG = xy_max(maxG,inputMat.at<Vec3b>(r+x,c+y)[1]);
                    maxR = xy_max(maxR,inputMat.at<Vec3b>(r+x,c+y)[2]);
                    
                }
            }
            
            dstImg.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(maxB);
            dstImg.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(maxG);
            dstImg.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(maxR);

        }
    }
    return dstImg;
}

Mat MyErodeFilter(const Mat& inputMat,int oddNum){
  
    Mat dstImg(inputMat.rows,inputMat.cols,inputMat.type(),Scalar::all(0));
    
    for(int i=0;i<inputMat.rows;i++){
        for(int j=0;j<inputMat.cols;j++){

            int mid = oddNum/2;//size 5x5
            int r = i-mid;
            int c = j-mid;
           
            uchar minB = 255;
            uchar minG = 255;
            uchar minR = 255;
           
            for(int x=0;x<oddNum;x++){
               
                for(int y=0;y<oddNum;y++){

                    //dealing of overflow of boundary
                    //eq: overflow region of elements is 0(zero)!(I think)
                    if(r + x < 0 || c + y < 0 ||r+x > inputMat.rows-1 || c+y > inputMat.cols-1){
                        continue;
                    }
                    
                    minB = xy_min(minB,inputMat.at<Vec3b>(r+x,c+y)[0]);
                    minG = xy_min(minG,inputMat.at<Vec3b>(r+x,c+y)[1]);
                    minR = xy_min(minR,inputMat.at<Vec3b>(r+x,c+y)[2]);
                    
                }
            }

            dstImg.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(minB);
            dstImg.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(minG);
            dstImg.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(minR);

        }
    }
    return dstImg;
}


Mat MyOpenFilter(const Mat& inputMat,int oddNum){
    return MyDilateFilter(MyErodeFilter(inputMat,oddNum),oddNum);
}

Mat MyCloseFilter(const Mat& inputMat,int oddNum){
    return MyErodeFilter(MyDilateFilter(inputMat,oddNum),oddNum); 
}

Mat MyTopHatFilter(const Mat& inputMat,int oddNum){
    return inputMat - MyOpenFilter(inputMat,oddNum);
}

Mat MyBlackHatFilter(const Mat& inputMat,int oddNum){
    return MyCloseFilter(inputMat,oddNum) - inputMat;
}

Mat MyMorphologicalGradientFilter(const Mat& inputMat,int oddNum){
    return MyDilateFilter(inputMat,oddNum) - MyErodeFilter(inputMat,oddNum);
}

