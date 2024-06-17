#include <iostream>
#include <string>

int main() {

    std::string Country;
    std::cout << "Where do you live?" << std::endl;
    std::cin >> Country;
    std::cout << "I've heard great things about " <<Country<<". I'd like to go sometime." << std::endl;

    return 0;
}