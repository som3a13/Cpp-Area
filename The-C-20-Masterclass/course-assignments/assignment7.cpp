#include <iostream>


int main() {


    int day;

    std::cout << "Which day is today [1 : Monday,..., 7 : Sunday] : " << std::endl;

    std::cin >> day;



    if (day < 1 || day > 7) {

        std::cout << "Error: Please enter a day between 1 and 7." << std::endl;

        return 1; 

    }

    int diffDay;
    std::cout << "Enter the day difference (positive or negative): ";
    std::cin >> diffDay;

    int pastDay = (day  -  diffDay ) % 7 +7;
    const char* DAY[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    std::cout << "Today is " << DAY[day-1] << " , if  we went " << diffDay << " days in the past, we hit ";
    // std::cout << pastDay << std::endl;
    switch (pastDay) {

        case 1:

            std::cout << "Monday." << std::endl;

            break;

        case 2:

            std::cout << "Tuesday." << std::endl;

            break;

        case 3:

            std::cout << "Wednesday." << std::endl;

            break;

        case 4:

            std::cout << "Thursday." << std::endl;

            break;

        case 5:

            std::cout << "Friday." << std::endl;

            break;

        case 6:

            std::cout << "Saturday." << std::endl;

            break;

        case 7:

            std::cout << "Sunday." << std::endl;

            break;

    }


    return 0;

}