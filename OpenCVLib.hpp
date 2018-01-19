#pragma comment(lib,"IlmImf.lib")
#pragma comment(lib,"libjasper.lib")
#pragma comment(lib,"libjpeg.lib")
#pragma comment(lib,"libpng.lib")
#pragma comment(lib,"libtiff.lib")
#pragma comment(lib,"opencv_calib3d2413.lib")
#pragma comment(lib,"opencv_contrib2413.lib")
#pragma comment(lib,"opencv_core2413.lib")
#pragma comment(lib,"opencv_features2d2413.lib")
#pragma comment(lib,"opencv_flann2413.lib")
#pragma comment(lib,"opencv_gpu2413.lib")
#pragma comment(lib,"opencv_highgui2413.lib")
#pragma comment(lib,"opencv_imgproc2413.lib")
#pragma comment(lib,"opencv_legacy2413.lib")
#pragma comment(lib,"opencv_ml2413.lib")
#pragma comment(lib,"opencv_nonfree2413.lib")
#pragma comment(lib,"opencv_objdetect2413.lib")
#pragma comment(lib,"opencv_ocl2413.lib")
#pragma comment(lib,"opencv_photo2413.lib")
#pragma comment(lib,"opencv_stitching2413.lib")
#pragma comment(lib,"opencv_superres2413.lib")
#pragma comment(lib,"opencv_ts2413.lib")
#pragma comment(lib,"opencv_video2413.lib")
#pragma comment(lib,"opencv_videostab2413.lib")
#pragma comment(lib,"zlib.lib")

#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>



/**
 *  First implementation (success!) 
 * 
 * 
 */
/*
template<class ...Args>
void println(Args ...args);//变长模板声明

template<> 
void println(){ //边界条件
    std::cout << std::endl;
}

template < class T,class... Args> 
void println(T t,Args... args){//偏特�?
    std::cout << t ;
    // std::cout << args... << std::endl;
    // std::cout << "sizeof = " << sizeof...(args) << std::endl;//args...的参数个�?
    println(args...);
    // println(args...);

}
*/

/**
 *  Second implementation (success,too!) 
 * 
 * 
 */
void println(){
    std::cout << std::endl;
}

template < class T,class... Args> 
void println(T t,Args... args){
    std::cout << t ;
    println(args...);
}

/**
 * ����������Ҫ�ɲ�Ҫ!
 */ 
// template<typename...Args>
// void print(Args...args);

template<typename T>
void print(T t){
    std::cout << t;
}

template<typename T,typename... Args>
void print(T t,Args ...args){

    std::cout << t;
    print(args...);

}
