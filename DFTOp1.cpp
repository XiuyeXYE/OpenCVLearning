#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    println("Scalar:all(1) = ",Scalar::all(1));
    /**
     * imread flags
     * IMREAD_UNCHANGED 	
     * If set, return the loaded image as is (with alpha channel, otherwise it gets cropped).
    *  IMREAD_GRAYSCALE 	
        If set, always convert image to the single channel grayscale image.
        IMREAD_COLOR 	
        If set, always convert image to the 3 channel BGR color image.
        IMREAD_ANYDEPTH 	
        If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
        IMREAD_ANYCOLOR 	
        If set, the image is read in any possible color format.
        IMREAD_LOAD_GDAL 	
        If set, use the gdal driver for loading the image.
        IMREAD_REDUCED_GRAYSCALE_2 	
        If set, always convert image to the single channel grayscale image and the image size reduced 1/2.
        IMREAD_REDUCED_COLOR_2 	
        If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2.
        IMREAD_REDUCED_GRAYSCALE_4 	
        If set, always convert image to the single channel grayscale image and the image size reduced 1/4.
        IMREAD_REDUCED_COLOR_4 	
        If set, always convert image to the 3 channel BGR color image and the image size reduced 1/4.
        IMREAD_REDUCED_GRAYSCALE_8 	
        If set, always convert image to the single channel grayscale image and the image size reduced 1/8.
        IMREAD_REDUCED_COLOR_8 	
        If set, always convert image to the 3 channel BGR color image and the image size reduced 1/8.
        IMREAD_IGNORE_ORIENTATION 	
        If set, do not rotate the image according to EXIF's orientation flag.
        */
    //��ȡ�Ҷ�ͼ��
    Mat srcImg = imread("p1.jpg",IMREAD_GRAYSCALE);
    if(!srcImg.data){
        println("��ȡsrcImgͼ��ʧ��!");
        return -1;
    }
    imshow("ԭʼͼ��",srcImg);
    //������ͼ����������ѳߴ�
    int m = getOptimalDFTSize(srcImg.rows);
    println("Original rows = ",srcImg.rows);
    println("Optimal(��ѵ�) rows = ",m);
    int n = getOptimalDFTSize(srcImg.cols);
    println("Original cols = ",srcImg.cols);
    println("Optimal(��ѵ�) cols = ",n);

    Mat padded;
    copyMakeBorder(srcImg,padded,0,m-srcImg.rows,0,n-srcImg.cols,BORDER_CONSTANT,Scalar::all(0));

    imshow("����߽���ͼ����ʲô������?",padded);

    //����Ҷ�任��Ľ���Ǹ���(ʵ�����鲿)
    Mat planes[] = {Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F)};
    Mat complexI;
    merge(planes,2,complexI);

    //����Ҷ�任
    dft(complexI,complexI);
    
    //������ʵ�����鲿,Ϊ������ƽ��������Բ�ĵľ���(��ֵ)��׼��
    split(complexI,planes);

    //z = x + y*i (i^2 = -1)
    //length(��ֵ) = sqrt(x^2+y^2)
    magnitude(planes[0],planes[1],planes[0]);
    Mat magnitudeImg =  planes[0];
    
    // imshow("��ֵ��ʲô������?",magnitudeImg);//White;if normalized,Black

    //�����������magnitudeImg���ʺ�����Ļ����ʾ,��ֵ��ɫ,��ֵ��ɫ.
    //����Ҫ��������.���·������õ�����Ȼ����: X1 = ln(X+1)
    magnitudeImg += Scalar::all(1);    
    //����Ȼ����
    log(magnitudeImg,magnitudeImg);

    
    // imshow("���ź�ķ�ֵͼ����ʲô������?",magnitudeImg);//White;if normalized,like the following

    magnitudeImg =magnitudeImg(Rect(0,0,magnitudeImg.cols & -2,magnitudeImg.rows & -2));
    
    // imshow("& -2 ���ͼ����ʲô������?",magnitudeImg);//White;if normalized,like the following
    int cx = magnitudeImg.cols / 2;
    int cy = magnitudeImg.rows / 2;

    Mat q0(magnitudeImg,Rect(0,0,cx,cy));
    //imshow("What does q0 look like?",q0);//White
    Mat q1(magnitudeImg,Rect(cx,0,cx,cy));
    Mat q2(magnitudeImg,Rect(0,cy,cx,cy));
    Mat q3(magnitudeImg,Rect(cx,cy,cx,cy));

    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    /**
     * void cv::normalize	(	InputArray 	src,
            InputOutputArray 	dst,
            double 	alpha = 1,
            double 	beta = 0,
            int 	norm_type = NORM_L2,
            int 	dtype = -1,
            InputArray 	mask = noArray() 
        )	
        Normalizes the norm or value range of an array.

        The function cv::normalize normalizes scale and shift the input array elements so that

            ��dst��Lp=alpha

        (where p=Inf, 1 or 2) when normType=NORM_INF, NORM_L1, or NORM_L2, respectively; or so that

            minIdst(I)=alpha,maxIdst(I)=beta

        when normType=NORM_MINMAX (for dense arrays only). The optional mask specifies a sub-array to be normalized. This means that the norm or min-n-max are calculated over the sub-array, and then this sub-array is modified to be normalized. If you want to only use the mask to calculate the norm or min-max but modify the whole array, you can use norm and Mat::convertTo.

        In case of sparse matrices, only the non-zero values are analyzed and transformed. Because of this, the range transformation for sparse matrices is not allowed since it can shift the zero level.
    */	
    // normalize(magnitudeImg,magnitudeImg,0,1,NORM_MINMAX);//opencv3
    normalize(magnitudeImg,magnitudeImg,0,1,CV_MINMAX);//opencv2;This is "the following"


    imshow("Ƶ�׷�ֵ",magnitudeImg);

    waitKey(0);
    return 0;
}