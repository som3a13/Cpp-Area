#include <iostream>

int main(int argc, const char** argv) {

    // literals are in program binary code like a=10;
    // variables which are loaded & allocated in memory



    //Const

    const int x=3;

    int *ptr=const_cast<int*>(&x);

    *ptr=5;

    //undefined behaviour
    std::cout << ptr << std::endl;
    std::cout << &x << std::endl;
    std::cout << x << std::endl;
    std::cout << *ptr << std::endl;

    //Constexpr at compile time c++11 to up

    const int y{4};
    constexpr int z{y};
    //check at compile time
    static_assert(y==4, "Error");

    //Constinit c++20

    


    return 0;



}