#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>


int main(){

    int age;
    std::string name;
    std::string fullname;

    // Input with spaces
    std::getline(std::cin,fullname);
    std::cout << fullname<<std::endl;
    // Input in same Line
    std::cin >> name >> age;
    std::cout << name<<std::endl;
    std::cout << age<<std::endl;

}