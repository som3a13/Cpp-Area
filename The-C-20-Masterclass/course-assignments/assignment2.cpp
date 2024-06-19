#include <iostream>

int main() {

    double fahrenheit{},celsius{};
    std::cout << celsius << std::endl;
    std::cout << "Please enter a degree value in Celsius" << std::endl;
    std::cin >>celsius;
    fahrenheit = (9.0 / 5) * celsius + 32;
    std::cout << celsius <<" Celsius is " << fahrenheit  << " Fahrenheit"<< std::endl;

    return 0;
}