#include <ios>
#include <iostream>
#include <iomanip>
int main(int argc, const char** argv) {


    int var{1}; // Declare & initialization
    std::cout << var << std::endl;
    var=3;//Assign
    std::cout << var << std::endl;

    bool state{false};
    std::cout << std::boolalpha; // convert from {0,1} to {true,false}
    std::cout << state << std::endl;


    auto var2 {33u}; //Auto type deduction
    var2=-22; // will cause error
    var2=90;
    std::cout << var2 << std::endl;

    auto var3{'a'};
    char var4=65; // 'A'
    std::cout << var4 << std::endl;
    std::cout << static_cast<int>(var4) << std::endl;


    std::cout << sizeof(bool) << std::endl;

    double var5{1.93277364};
    std::cout << std::setprecision(3);
    std::cout << var5 << std::endl;


        //Precedence which will be evaluated first
    // Associativity which order to start with or direction
    int x{4},y{2},z{5};
    int result= x*z+x/y; //Start first with * / then +   ,, direction left to right
    std::cout << result << std::endl;
    result = x++ + --y - z++;
    std::cout << result << std::endl;
    x= 2%3; //rem 2 4%3 =  rem 1
    std::cout << x << std::endl;
    return 0;

}