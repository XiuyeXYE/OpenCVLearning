#include<opencv2/core/core.hpp>
#include"MyTransformation.hpp"
using namespace cv;

Mat MySmallTwice(const Mat& srcImg){

    int rows = srcImg.rows/2;
    int cols = srcImg.cols/2;

    Mat dstImg(rows,cols,srcImg.type());
    /**
     * 
     * get rid of even lines (rows,cols)
     * keep odd lines (rows,cols)
     * 
     * in fact,first line (from zero) of img is the beginning of odd lines!
     * 
     */ 
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            dstImg.at<Vec3b>(i,j)[0] = srcImg.at<Vec3b>(2*i,2*j)[0];
            dstImg.at<Vec3b>(i,j)[1] = srcImg.at<Vec3b>(2*i,2*j)[1];
            dstImg.at<Vec3b>(i,j)[2] = srcImg.at<Vec3b>(2*i,2*j)[2];
        }
    }
    
    return dstImg;
}

/**
 * 图像在每个维度上(width,height)扩大原来的两倍.
 * 新增偶数列偶数行,值为0.
 * 使用某种过滤算法填充偶数行列.
 * 因为图像放大后,新增像素点的值是未知的,是根据相邻像素点推测的.
 * 而推测的方法可以是过滤器平滑化(smooth)处理哪些无值的点.
 */
//与OpenCV比较后锯齿处理的不太好,也许还有其他的缺点
Mat MyLargeTwice(const Mat& srcImg,int oddNum/*声明上写了默认值,此处不写,默认值=3*/){//5x5 7x7 9x9 ...效果差

    int rows = srcImg.rows*2;
    int cols = srcImg.cols*2;

    //odd lines (rows,cols) save src. 
    Mat dstImg1(rows,cols,srcImg.type(),Scalar::all(0));
    //In fact,first line begins from zero.
    for(int i=0;i<srcImg.rows;i++){
        for(int j=0;j<srcImg.cols;j++){
            dstImg1.at<Vec3b>(2*i,2*j)[0] = srcImg.at<Vec3b>(i,j)[0];
            dstImg1.at<Vec3b>(2*i,2*j)[1] = srcImg.at<Vec3b>(i,j)[1];
            dstImg1.at<Vec3b>(2*i,2*j)[2] = srcImg.at<Vec3b>(i,j)[2];
        }
    }

    //deal with even lines(rows,cols)(value = 0)
    Mat dstImg2(rows,cols,dstImg1.type(),Scalar::all(0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            
            //以下的这步会影响实现效果
            //不太好平滑化(smooth)处理后有黑点(麻点)
            //推测是通道值bgr低的像素多数没有被平滑化(smooth)处理好!
            // int bv = dstImg1.at<Vec3b>(i,j)[0];
            // int gv = dstImg1.at<Vec3b>(i,j)[1];
            // int rv = dstImg1.at<Vec3b>(i,j)[2];
            
            // if(bv != 0 || gv != 0 || rv != 0){
            //     continue;
            // }

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
                    if(r + x < 0 || c + y < 0 ||r+x > rows-1 || c+y > cols-1){
                        continue;
                    }
                    //typedef Vec<uchar, 3> cv::Vec3b
                    int blueValue = dstImg1.at<Vec3b>(r+x,c+y)[0];
                    int greenValue = dstImg1.at<Vec3b>(r+x,c+y)[1];
                    int redValue = dstImg1.at<Vec3b>(r+x,c+y)[2];
                    //根据值不为0的像素点.
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
                dstImg2.at<Vec3b>(i,j)[0] = saturate_cast<uchar>(sumB/notZeroItemNum);
                dstImg2.at<Vec3b>(i,j)[1] = saturate_cast<uchar>(sumG/notZeroItemNum);
                dstImg2.at<Vec3b>(i,j)[2] = saturate_cast<uchar>(sumR/notZeroItemNum);
            }
        }
    }
    return dstImg2;
}
