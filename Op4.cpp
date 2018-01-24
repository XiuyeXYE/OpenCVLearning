#include"OpenCVLib2.hpp"

class A{
public:
    bool operator==(A &a){
        return this == &a;
    }

};

std::ostream& my_endl(std::ostream& out){
    return out << "my_endl" << std::endl;
}

int main(){

    A a;
    println(std::boolalpha,a == a);
    A b = a;
    println(std::boolalpha,a == b);
    A c(a);
    println(std::boolalpha,c == a);

    std::cout << my_endl;

    println(my_endl);

    return 0;
}