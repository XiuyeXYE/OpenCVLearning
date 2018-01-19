
#ifndef __MY_MATH_H
#define __MY_MATH_H

/**
 * a b t args 参数必须相同的类型,否则报错!
 * 
 * 
 * 
 */ 

template<class T>
T xy_max(T a,T b){
    return a>b?a:b;
}

template<class T,class...Args>
T xy_max(T t,Args ...args){
    return xy_max(t,xy_max(args...));
}

template<class T>
T xy_min(T a,T b){
    
    return a>b?b:a;
}

template<class T,class...Args>
T xy_min(T t,Args...args){

    return xy_min(t,xy_min(args...));
}


#endif