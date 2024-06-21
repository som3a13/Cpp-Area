#include <cstddef>
#include <iostream>
#include <ostream>



int main(int argc, const char** argv) {
 

    for (std::size_t i{0}; i<10; ++i) {

    std::cout << "/* message */" << std::endl;
    }


    //Ranged based for loop
    int arr[]={1,2,3,4,5};
    
    for(auto i :arr)
    {
        std::cout <<i << std::endl;
    }

    //Exercise

    /*
    
    
    unsigned int sum_up_to_99(){
    unsigned int sum{};
    
    //Don't modify anything above this line
    //Your code will go below this line
    
    for(std::size_t i{0};i<100;i++)
    {
        sum +=i;
    }
    
    //Your code will go above this line
    //Don't modify anyting below this line

     return sum;
    }
    
    */
    

    //EX

    /*
                void print_uppercase(){
                            for( unsigned char i{0}; i< 255 ; ++i){
                                
                            //Don't modify anything above thie line
                            //Your code goes below this line
                            if(i>=65 && i <=90)
                            {
                                if(i==90)
                                {
                                    std::cout << i;
                                    break;
                                }
                            std::cout << i << " " ;

                            }

                            //Your code goes above this line
                            //Don't modify anything after this line
                        }
                }
    */






    // Comma operator

    int x{1},y{2},z{3};

    int result = (z++,y,z+=1);  // from left to right evaluation , then the right will be assigned to result

    std::cout << result << std::endl;



    //EX

    /*

void print_multiples_of_3(){
    
    
    std::vector<int> numbers {1,21,4,5,7,3,9,3,5,17,15};

    //Don't modify anything above this line
    //Your code should go below this line
    for(auto i : numbers)
    {
        if(i % 3 ==0 )
        {
            std::cout << i << " ";
        }
    }
    //Your code should go above this line
    //Don't modify anything below this line
    
}
    */


    //Ex 

    /*
    void multiples_of_19(){
    
    //Don't modify anything above this line
    //Your code will go below this line
    const std::size_t count{1000};
    std::size_t i{100};
    while(i<=count)
    {
        if(i % 19 ==0)
        {
            std::cout << i << " ";
        }
        ++i;
    }
   //Your code will go above this line
   //Don't modify anything below this line
}
    */
    //infinite loop
    // for(;;)
    // {
    //         std::cout << "/* message */" << std::endl;
    // }
    // while(1);

    // underflow happen  with unsigned as it goes to -1 which will be (256^4 -1 )
    for(signed int i{10}; i>=0; --i)
    {
        std::cout << i << std::endl;
    }

    //c++20
    for(auto multiplier{2};auto i : arr)
    {
            std::cout << i*multiplier << std::endl;
    }

    return 0;
}