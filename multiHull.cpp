#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat img(600,600,CV_8UC3);
    RNG& rng = theRNG();

    while(true){
        int count = rng.uniform(3,103);
        vector<Point> points;

        for(int i=0;i<count;i++){
            Point point;
            point.x = rng.uniform(img.cols/4,img.cols*3/4);
            point.y = rng.uniform(img.rows/4,img.rows*3/4);
            points.push_back(point);
        }  

        RotatedRect box = minAreaRect(Mat(points));
        Point2f vertex[4];
        box.points(vertex);

        img = Scalar::all(0);

        for(int i=0;i<count;i++){
            circle(img,points[i],3,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),CV_FILLED,CV_AA);

        }
        for(int i=0;i<4;i++){
            line(img,vertex[i],vertex[(i+1)%4],Scalar(100,200,255),2,CV_AA);

        }
        imshow("Effect",img);

        char key =waitKey(0);
        if(key == 'q'){
            break;
        }

    }

    waitKey(0);
    return 0;
}