#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <array>
#include <functional>
#include <iterator>
#include <string>
#include <type_traits>
#include <vector>

class TestArea
{
    public:

        // int fun(int x=2 ,int y) Missing default param  should be on the right var

        /*Function Overloading   : should different arguments*/

        int fun(int x,int y, int z=10)
            {

                return 0;
            }
        double fun(double x,double y)
        {


            return 0;
        }


    enum class Traffic {
        GREEN,
        RED,
        YELLOW
     };
    Traffic color= Traffic::GREEN;
     std::string to_string(const Traffic & color)
     {

        switch (color)
        {
            case Traffic::GREEN : return "GREEN";break;
            case Traffic::RED : return "RED";break;
            case Traffic::YELLOW :return "YELLOW";break;

        default:
            break;
        }
     }




};


/*Pointer to function*/
typedef int&(*funptr)(int,int);

std::function<int(int,int)> fun1=[](int x,int y)
    {
        
        return x+y;
    };
int& fun3()
{
    static int x=3;

    return x;
}




int main(int argc, const char** argv) {

    TestArea test1;



    //objdump -S -t a.out --demangle
    test1.fun(static_cast<int>(1.2),2);




    /***Arrays */

    int arr1[4]{1,2,2,90};
    auto it1 =std::max_element(&arr1[0],&arr1[4]);
    std::cout << *it1<< std::endl;
    auto it= std::find(&arr1[0],&arr1[4],11);
    if(it!=&arr1[4])
    {
        int loc = std::distance(&arr1[0],   it);
                std::cout << loc << std::endl;

    }
    else
    {
        std::cout << "/* message */" << std::endl;
    }
    for(auto &i : arr1)
    {
        std::cout << i << "*";
    }

    int arr[3][3]={
                    {3,3,3},
                    {3,3,3},
                    {3,3,3}
                    };

    for(std::size_t i ; i < std::size(arr1);i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::array<int,5> arr2{1,2,3,4,4};

    std::cout <<     *(arr2.end()-1); // last element 
    for(auto i : arr2)
    {
        std::cout << i << std::endl;
    }

    /***Pointers */


    const int x=6;

    int *ptr= const_cast<int *>(&x);
    *ptr=11;

    std::cout << *ptr << std::endl;
    ptr=nullptr;
    void *ptr1=(int *)0;
    
    std::cout << ptr<< std::endl;

    /*Dynamic memory*/
    void * ptr2= new int(5);
    std::cout << *(int *)ptr2 << std::endl;
    delete ptr2;
    ptr2=nullptr;

    int *ptr3= (int *)malloc(sizeof(int));
    *ptr3=1024;
    std::cout << *ptr3 << std::endl;
    free(ptr3);
    ptr3=nullptr;
    /*Segemntation fault as the area allocated in heap was deleted*/
    // *ptr3=10;


    /*Check Memory Leakage*/
    // g++ main.cpp -fsanitize=address  usage = a.out
    //valgrind --leak-check=full ./a.out


    std::array<int, 5> arr3{1,23,5,6,7};

    int *ptr4= arr3.data();
    std::cout << *(ptr4) << std::endl;




    /*****Pointers to function */


    // funptr PTR1;
    // PTR1=fun3;
    // std::cout <<     PTR1(1,2)<< std::endl;
    // int & (*funptr2)(int,int)=fun3;
    // std::cout <<     funptr2(1,6)<< std::endl;



    /*****Refrence*/
    const int z=10;
     int &x1=const_cast<int&>(z);
    x1=20; // z will not change if it's const
    std::cout << &x1 << std::endl;
    std::cout << &z << std::endl;


    /*Auto*/

    auto lst = {1,2,3,4,5};
    lst.size();

    /***Casting */




    char *x2 = new char('A');
    int *x3= reinterpret_cast<int *>(x2);
    std::cout << static_cast<char>(*x3) << std::endl;


    /*Misra rules : avoid const cast */
    const int val=10;
    const int *ptr5=(&val);
    int *ptr6=const_cast<int*>(ptr5);
    *ptr6=20;
    std::cout << val << std::endl;


    /*Lambda Expression*/

    std::function<int()> lam=[x2]()
    {

        return *x2;
    };
    std::cout << lam() << std::endl;

    std::vector<int>v{3,100,5,6,7,8,900};
    for(auto i: v)
    {
        std::cout << i << " ";
    }
    int flag{};
    std::for_each(v.begin(), v.end(),[&flag](int i)
    {
        if(i==7)
        {
            flag=1;
        }
    }
    );

    std::cout << flag << std::endl;
    auto i1=std::find(v.begin(),v.end(),900);
    if(i1!=v.end())
    {
        int index = std::distance(v.begin(), i1);
        std::cout << index << std::endl;
    }
    std::sort(v.begin(),v.end(),[](int a,int b)
    {
        return a>b;
    });
    auto i =std::max_element(v.begin(),v.end());
    if(i!=v.end())
    {
         std::cout << *(v.end()-1)<< std::endl;
        std::cout << *i<< std::endl;
        std::cout <<  v.at(5)<< std::endl;
    }




    auto lst2={1,2,3,4,22,20};
   int i2= std::max(lst2);
    std::cout << i2 << std::endl;

    std::sort(lst2.begin(),lst2.end());


    std::string name{"SOm3a"};
    auto i4= name.find('s');

    if(i4!=std::string::npos)
    {
        std::cout << i4 << std::endl;

    }
    else
    {
        std::cout << "not found" << std::endl;
    }




    float dec=3.5;
    int vall{(int)dec};

    /**ENUM */
    
    enum class MyClass {
        ON,
        OFF,
        IDLE
     };

    int xo=static_cast<int>(MyClass::ON);
    MyClass en1=MyClass::OFF;
    
    std::cout <<(int) MyClass::ON << std::endl;
    
  


    switch(en1)
    {
        case MyClass::ON:
            std::cout << "/* message */" << std::endl;
        case MyClass::OFF:
            std::cout << "/* message */" << std::endl;
            
    }



    /**Struct */
    struct traffic
    {
        unsigned char x;
        int y;
    };

    traffic ob1 ={
        .x=10,
        .y=1
    };
    std::cout << ob1.y << std::endl;



    TestArea a1;
    std::cout <<     a1.to_string(TestArea::Traffic::RED)<< std::endl;    

    

        fun3()=10;
        std::cout << fun3()<< std::endl;


    return 0;
}


