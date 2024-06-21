#include <iostream>

int main(int argc, const char** argv) {
 
    unsigned char i='A';
    unsigned char *ptr=&i;

    std::cout << sizeof(ptr) << std::endl;
    std::cout << *ptr << std::endl;
    // Print the address of i
    std::cout << "Address of i: " << static_cast<void*>(&i) << std::endl;

    // Print the address stored in ptr
    std::cout << "Address stored in ptr: " << static_cast<void*>(ptr) << std::endl;
    ptr=nullptr;
    std::cout << static_cast<void*>(ptr) << std::endl;

    // The const char* type is used to point to this string literal.
    const char *msg{"Hello world!"};
    std::cout << &msg << std::endl;
    char msg2[]{'h','i'};
    if(msg2[2]=='\0')
    {
        std::cout << "/* message */" << std::endl;
    }
    //will initialize with nullptr
    int *ptr1{};
    std::cout << static_cast<void*>(ptr1) << std::endl;



 //EX
    int data[]{11,2,52,53,9,13,5,7,12,11};
      int * max_address;
  
  //Don't modify anything above this line
  //Your code will go below this line
  int max{};
  for(std::size_t i{1};i<10;i++)
    {   
        if(data[i]>max)
        {
 
                max=data[i];
                max_address=&data[i];
         


        }
    }
    std::cout << max_address << std::endl;





    int arr[5] = {1, 2, 3, 4, 5};
    int (*ptr3)[5]=&arr;
    std::cout << *(*ptr3+14) << std::endl;
std::cout << *(arr+3) << std::endl;



    //Ex
        //Don't modify anything above this line
    //Your code will go below this line
    
    // std::cout << "The element "<<  offset<<" slots away from the beginning is : "  << *(data+offset);
      //Your code will go above this line
      //Don't modify anything below this line


    



    return 0;





}