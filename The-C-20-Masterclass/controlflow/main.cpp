#include <ios>
#include <iostream>

int main(int argc, const char** argv) {
    
    int num1{2},num2{3};

    //IF statement
    if(num1>num2)
    {
        std::cout << "num1  greater than num2" << std::endl;
    }
    else if(num2>num1)
    {
        std::cout << "num2 greater" << std::endl;
    }
    else
    {
        /*nothing*/
    }
    
    //ternary
    bool result = (num1<num2) ? 1 :0;
    std::cout << std::boolalpha <<result << std::endl;

    // switch case
    const int x=2;
    switch (num1) {
    case x : {
                std::cout << "num1 =1" << std::endl;
                break;
            }
    case 3 : std::cout << "num1 =3" << std::endl;
            break;
    default: break;
    }

    int flag =1;

    if(flag==1)
    {
        std::cout << "test1" << std::endl;
        flag=0;
    }
    std::cout << flag << std::endl;


    //Exercise Leap year


    bool is_leap{};
    unsigned int year;
    //Don't modify anything above this line
    //Your code goes below this line
    if(!(year % 4))
    {
        is_leap=true;
    }
    else
    {
        is_leap=false;
    }
    std::cout << is_leap << std::endl;


    //0 is only evaluated to flase
    //underflow    
    unsigned int i=-3 ; 
    if(i)
    {
        std::cout << i << std::endl;
    }



    //If will be evaluated at compile time
    //c++14
    constexpr int i2=3;
    //c++17
    if constexpr(i2)
    {
        std::cout << "/* message */" << std::endl;
    }





    //if with initializer  c++17
    bool go{true};
    if(int speed{10};go)
    {
        if(speed > 5)
        {   
            std::cout << "ready to go" << std::endl;
        }
        
    }   

    // switch with initializer c++17

    switch ( int speed{10};go){
        case 1 : // int x{1} compiler error  , it will reserve location for x first and if it enters will initalize it 
                int x;
                x=1;
                std::cout << "go" << std::endl;
                std::cout << speed << std::endl;
                std::cout << x << std::endl;
                // std::cout << y << std::endl;
                break;
        case 0 : std::cout << "stop" << std::endl;
                int z;
                z=1;
                break;
    }
    return 0;
}