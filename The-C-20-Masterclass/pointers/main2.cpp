#include <cstddef>
#include <iostream>

int main(int argc, const char** argv) {
    

    int *ptr=new int(5);
        delete ptr;  


    ptr=new int(6);
    delete ptr;  
 
    std::cout << *ptr << std::endl;
 
    return 0;
}