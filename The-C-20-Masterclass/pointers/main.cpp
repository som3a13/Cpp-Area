#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>

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
    std::cout << **(&arr) << std::endl;
        std::cout << *arr << std::endl;

    std::cout << (*ptr3)[3] << std::endl;
std::cout << *(arr+3) << std::endl;




    //Ex
        //Don't modify anything above this line
    //Your code will go below this line
    
    // std::cout << "The element "<<  offset<<" slots away from the beginning is : "  << *(data+offset);
      //Your code will go above this line
      //Don't modify anything below this line


    

    //EX
    /*
    int * min_address;

  // Don't modify anything above this line
  //Your code should go below this line
  //REMEMBER !ONLY POINTER ARITHMETIC SHOULD BE USED TO ACCESS ARRAY DATA
    int min{*(data)};
    for(std::size_t i{1};i<size;i++)
    {
        if(*(data+i)<min)
        {
            min=*(data+i);
            min_address=(data+i);
        }
    }
  */


    //Dangling pointer

    int *ptr4;
    // std::cout << *ptr4 << std::endl; //undefined behaviour 

    //NEW
    try{
                int *pt5=new int[10000000000000000];
                    delete[] pt5;
    std::cout << *pt5 << std::endl;  // pt5 now has data of garabage address
    pt5=nullptr;

    }catch(std::exception& ex){
                    std::cout << "  Something went wrong : " << ex.what() << std::endl;
    }
    int *pt6= new(std::nothrow) int[1000000000000];
    if(pt6==nullptr)
    {
        std::cout << "failed to alloc" << std::endl;
    }

    //swap
    int x{1};
    int y{2};
    x=x+y;
    y=x-y;
    x=x-y;

    std::cout << y << std::endl;
    std::cout << x << std::endl;

    x=x^y;
    y=x^y;
    x=x^y;
        std::cout << y << std::endl;
    std::cout << x << std::endl;

    //EX
/*
        unsigned int size3=size2+size1;
        int *ptr=new int[size3];
    for(std::size_t i{};i<(size1+size2);i++)
    {

        if(i<size1)
        {
            ptr[i]=data1[i];
        }
        else
        {
            ptr[i]=data2[i-size1];
        }
    }
    for(unsigned int i{};i<size3;i++)
    {
        std::cout << ptr[i] << " ";
    }*/

    


    void *ptr7{};
    // ptr7=new int(5);
    // // delete (int*)ptr7;
    // std::cout << ptr7 << std::endl;


    try{
        if(ptr7!=nullptr)
        {
            std::cout << "/* message */" << std::endl;
        }
        else
        {
            throw std::runtime_error("it's null");
        }
    }catch(std::exception &ex)
    {
        std::cout << "Error:"<<ex.what() << std::endl;
    }
    //Dynamically allocated arry dont support  ranged for or std::size
    return 0;





}