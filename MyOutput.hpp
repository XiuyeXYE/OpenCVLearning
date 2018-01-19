
#ifndef __My_Print_And_Println
#define __My_Print_And_Println
/**
 *  First implementation (success!) 
 * 
 * 
 */
/*
template<class ...Args>
void println(Args ...args);

template<> 
void println(){ 
    std::cout << std::endl;
}

template < class T,class... Args> 
void println(T t,Args... args){
    std::cout << t ;
    // std::cout << args... << std::endl;
    // std::cout << "sizeof = " << sizeof...(args) << std::endl;
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
 * 以下声明可要可不要!
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
#endif