#include"OpenCVLib2.hpp"
using namespace cv;

int main(){

    Mat img(600,600,CV_8UC3);

    RNG& rng = theRNG();

    while(true){
        char key;
        int count = (unsigned)rng%100 + 3;
        vector<Point> points;

        for(int i=0;i<count;i++){
            Point point;
            point.x = rng.uniform(img.cols/4,img.cols*3/4);
            point.y = rng.uniform(img.rows/4,img.rows*3/4);

            points.push_back(point);
        }
        vector<int> hull;
        convexHull(Mat(points),hull,true);

        img = Scalar::all(0);
        for(int i=0;i<count;i++){
            circle(img,points[i],3,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),CV_FILLED,CV_AA);
            
        }
        int hullcount = (int)hull.size();
        Point point0 = points[hullcount - 1];

        for(int i=0;i<hullcount;i++){
            Point point = points[hull[i]];
            line(img,point0,point,Scalar(255,255,255),2,CV_AA);
            point0 = point;
        }
        imshow("effect",img);
        char word = waitKey(0);
        if(word == 'q'){
            break;
        }
    }
    return 0;
}
