#include <iostream>



/*
    Variable lifetime : when the varibale will die
    Variable scope : where can variable be accessed


*/


int  global{19};

int main(int argc, const char** argv) {
    
    std::cout << global << std::endl;
    {
        int local{3};
    }
    return 0;
}