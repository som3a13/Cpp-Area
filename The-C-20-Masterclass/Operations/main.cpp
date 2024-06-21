#include <ios>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <limits>
#include <math.h>

int main(int argc, const char** argv) {

    //Precedence which will be evaluated first
    // Associativity which order to start with or direction
    int x{4},y{2},z{5};
    int result= x*z+x/y; //Start first with * / then +   ,, direction left to right
    std::cout << result << std::endl;
    result = x++ + --y - z++;
    std::cout << result << std::endl;
    x= 2%3; //rem 2 4%3 = 1
    std::cout << x << std::endl;
    //Compund operations
    x+=5;
    // Relational operations
    int num1{3},num2{4};
    std::cout << std::boolalpha;
    std::cout << (num1<num2) << std::endl;
    bool res= (num1 == num2);
    std::cout << res << std::endl;
    // logical Operations
    bool test = res && num2; // false && true = false ,0
    std::cout << test << std::endl;
    std::cout << !test << std::endl; 


    //limits

        std::cout << std::numeric_limits<short>::is_signed << std::endl;
        std::cout << std::numeric_limits<short>::digits << std::endl;



    //Math 
    /*
    floor , ceil , round , sqrt ,tan , power, log ,abs
    */
    double weight{7.3};

    std::cout << std::round(weight) << std::endl;

    double a{6.7};
    double hex_area = 3*std::sqrt(3)/2 * std::pow(a,2);



    // Weired integral types :: casting

    unsigned short var7{1};
    unsigned char var8{2};
    // int is the smallest(memory size) 4 bytes integer type for which arithmetic operations are supported
    auto res1=var7+var8;
    std::cout << "size of res : "<<sizeof(res1) << std::endl;





    //Output formating

    /*
        std::flush
        std:setw()
        std::showpos; show positive sign
        std::hex;
        std::oct;
        std::showbase;
        std::uppercase
        std::setprecision
        std::showpoint

    */
    std::cout << std::setfill('-');
    std::cout << std::uppercase;
    std::string name = "som3a";
    int o=717171;

    std::cout << std::setw(5)<<"Som3a"<< std::setw(5)<<"55"<< std::setw(10)<<"Egypt" <<name << std::showbase<<std::hex <<o<< std::endl;




    return 0;



}