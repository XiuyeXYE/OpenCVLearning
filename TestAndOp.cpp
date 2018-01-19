#include<iostream>
#include"MyOutput.hpp"

int main(){

    println("1 & -2 = ",1 & -2);//0
    /**
     *      2   0010    0010
     *   &  -1  1001    1111 
     *          0000    0010
     *          0       2
     */
    println("2 & -1 = ",2 & -1);//2
    return 0;
}

