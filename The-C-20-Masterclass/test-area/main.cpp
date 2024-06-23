#include <iostream>

int main(int argc, const char** argv) {
 
    short x=48; 
    short &y=x ;
    std::cout << &x << std::endl; 
    std::cout << &y << std::endl; 
    std::cout << sizeof(x) << std::endl;
    std::cout << x << std::endl;
    return 0;
}