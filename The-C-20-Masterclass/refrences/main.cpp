#include <iostream>
#include <cstring>

int main(int argc, const char** argv) {


    //Undefined behavior
     const int x{10};
    int &ref=const_cast<int &>(x);
    ref=3;
    std::cout << x << std::endl;
    std::cout << &x << std::endl;
    int *ptr=const_cast<int*>(&x);
    *ptr=4;
    std::cout << x << std::endl;


    //refrence one initialized will not change memory loc


    int data[]{10,30,20,10};
    for(auto &data:data)
    {
        data=data*10;
    }
    std::cout << data[3] << std::endl;



    return 0;
}