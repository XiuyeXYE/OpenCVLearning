#include<iostream>

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
void println(T t,Args... args){//偏特化
    std::cout << t ;
    // std::cout << args... << std::endl;
    // std::cout << "sizeof = " << sizeof...(args) << std::endl;//args...的参数个数
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


// void tprintf(const char* format) // 基函数
// {
//     std::cout << format;
// }
 
// template<typename T, typename... Targs>
// void tprintf(const char* format, T value, Targs... Fargs) // 递归变参数函数
// {
//     for ( ; *format != '\0'; format++ ) {
//         if ( *format == '%' ) {
//            std::cout << value;
//            tprintf(format+1, Fargs...); // 递归调用
//            return;
//         }
//         std::cout << *format;
//     }
// }

int main(){

    // println(1);
    println(1,' ','2'," ",3,' ',"4 5 6 7 8 9 10",'\n',"abcdefghijklmn");

    return 0;
}