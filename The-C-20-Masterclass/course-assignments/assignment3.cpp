#include <ios>
#include <iostream>

int main() {

    double width{},length{},height{},volume{},base_area{};
   
    

    std::cout << "Welcome to box calculator. Please type in length, width and height information : " << std::endl;

    std::cout << "length : ";
    std::cin >> length;
    std::cout << "width : ";
    std::cin >> width;
    std::cout << "height : ";
    std::cin >> height;
    base_area = length * width;
    volume = base_area *height;
    // std::cout << std::showpoint;
    std::cout << "The base area is : "<<base_area << std::endl;
    std::cout << "The volume is : "<<volume << std::endl;
    
    return 0;
}