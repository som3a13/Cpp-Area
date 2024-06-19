#include <iostream>

bool oddEven(int num)
{   
    if (num % 2 ==0)
    {   
        return true;
    }

    return false;
}

int main(int argc, const char** argv) {
    int num{};
    std::cout << "Please type in an integral value" << std::endl;
    std::cin >> num;
    std::cout << num << (oddEven(num)?" is even":" is odd") << std::endl;
    return 0;
}