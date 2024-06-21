#include <iostream>

int main(int argc, const char** argv) {


    // IMPLICT
    double price{45.6};
    int units{10};

    units = price;  // narrowing conversion price is int now

    auto result = price * units; // units converted to double
    std::cout << sizeof(result) << std::endl;



    //EXPLICIT


    double x{1.3};
    double y{2.3};
    double sum = static_cast<int>(x)+y; 

    std::cout <<   static_cast<int>(sum) << std::endl;
    unsigned char z= 256; // overflow 100000000 =0
    std::cout << static_cast<int>(z) << std::endl;
    z=-4; // Underflow   254 255 0 1     256-2=254 11111110
    std::cout << static_cast<int>(z)  << std::endl;
    return 0;
}