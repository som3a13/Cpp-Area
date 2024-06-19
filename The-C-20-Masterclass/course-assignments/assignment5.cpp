#include <iostream>

void ageChecker(int age)
{   
    if (age >= 21  )
    {   
        if(age <=39)
        {
            std::cout << "You are eligible for the treatment" << std::endl;
        }
        else
        {
            std::cout << "Sorry, you are too old for the treatment" << std::endl;

        }
    }
    else 
    {
        std::cout << "Sorry, you are too young for the treatment" << std::endl;

    }

}

int main(int argc, const char** argv) {
    int age{};
    std::cout << "Please type in an your age : " << std::endl;
    std::cin >> age;
    ageChecker(age);
    return 0;
}