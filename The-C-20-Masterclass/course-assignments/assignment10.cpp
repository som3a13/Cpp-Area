#include <iostream>
#include <ctime>

int main(){
    //srand() has to run once per program run
    std::srand(std::time(0)); // Seed

    bool end{ false };

    std::cout << "Welcome to the greatest calculator on Earth! " << std::endl;

    unsigned int MAX_NUMBER {200};

    while (!end) {

        int num1 = static_cast<size_t>((std::rand() % MAX_NUMBER));
        int num2 = static_cast<size_t>((std::rand() % MAX_NUMBER));
        int operation = static_cast<size_t>((std::rand() % 3));
        
        switch(operation){

            case 0 : 
             std::cout << "What's the result of " << num1 << " + " << num2 << " : ";
            break;
            case 1 :
             std::cout << "What's the result of " << num1 << " - " << num2 << " : ";
            break;
            default : 
              std::cout << "What's the result of " << num1 << " * " << num2 << " : ";
            break;
        }

        int result;
        std::cin >> result;

            switch(operation){
            case 0 : 
             if(result == (num1 + num2)){
                 std::cout << "Congratulations! You got the result "
                     << result << " right!" << std::endl;
             }else{
                 std::cout << "Naah! the correct result is : "
                     << num1 + num2 << std::endl;
             }
            break;
            case 1 :
             if(result == (num1 - num2)){
                 std::cout << "Congratulations! You got the result "
                     << result << " right!" << std::endl;
             }else{
                 std::cout << "Naah! the correct result is : "
                     << num1 - num2 << std::endl;
             }
            break;
            default : 
             if(result == (num1 * num2)){
                 std::cout << "Congratulations! You got the result "
                     << result << " right!" << std::endl;
             }else{
                 std::cout << "Naah! the correct result is : "
                     << num1 * num2 << std::endl;
             }
            break;
        }

        std::cout << std::endl;
        std::cout << "Do you want me to try again ? (Y | N) : ";

        char go_on;
        std::cin >> go_on;

        end = ((go_on == 'Y') || (go_on == 'y')) ? false : true;

    }

    std::cout << "See you later!" << std::endl;

    return 0;
}