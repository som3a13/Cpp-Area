#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <utility>
#include <vector>




/*Rule of 5 [Constructor,Copy,Move,=Move,=Copy] */
class MyClass;
 

/*Polymorphic class*/
class Test
{
    public:

/*To avoid direct assigning */
    explicit Test(){
            std::cout << "Hi From Default Constructor " << std::endl;

    }; 
     /*Best practice is to use initializer list less instructions*/
    Test(int id1,std::string name1,int *ptr1):id(id1),name(name1),ptr(ptr1)
    {
        std::cout << "Hi From Initilizer list Constructor" << std::endl;
        // this->val1=10;
    }

/*Shallow copy : copies everything as it is , so if pointer exist it will take same address*/
/*Deep copy : implementation of copy constructor to solve that problem and each object has its data */
/* Default copy constructor is shallow copy so it's needed to implement copy constructor if there is a pointer*/
/*Refrence : easy to use no headache , same size of ptr as it is actually const ptr , less instruction so more optimization , should be initialezed with existed variable has valid address , no dynamic memory , alias , no nullptr can passed to it so it more safe
   Pointer : headache when using dynamic memory allocation , should be initialized , more instructions,should make derefrencing to acess data , equires additional checks for validity if nullptr b4 derefrencing
*/
/*Memory wise which is better ? pointer or ref :   using  ref with cout in cpp it has no address but the address which it refer to so we use gdb and check disassembly to see if ref takes a memory or no 
And answer is yes ref takes memory to store that address in it :D, */
/*check disassembly and search for ref location and which address it store in it and then using gdb check the register & address */
/* in gdb :x/xg $rbp - 0x***  */
/*Output be like : 0xaddress of ref : 0xaddress of data*/

// 0x0000555555555195  <_Z3funRi+12>:  mov    -0x8(%rbp),%rax , move value in ref adress[rbp-0x8] which is the number address then store in rax register  
/*why by ref not by value ? as to avoid copying the object it self and to direct refer to original object*/
/*Why const ? to promise not modify it */

    Test(const Test& obj )
    {
        this->id=obj.id;
        this->name=obj.name;

        if(this->ptr!=nullptr)
        {
            delete this->ptr;
            ptr=nullptr;
        }
        if(obj.ptr){
             this->ptr=new int(*obj.ptr);

        }
        
        std::cout << "Hi From Copy Constructor " << std::endl;

    }

/*if no copy assignment , pointers will be with same addr and will affect each other 
 on deleting one of them at Destruct cause an error Core dump
 With no copy operator handling with pointer is bad*/

/*to print obj 
std::ostream& operator<<(std::ostream &out,const Complex&obj)
{
   return out << obj.a << "+i" << obj.b;
}*/

/*& invoke that the return will be assigned directly to the object without creating a temp obj ,, and op= works  when Complex a;// a=b*/
    Test &operator=(const Test&obj)
    {
        if(this==&obj)
        {
            return *this;
        }
        this->id=obj.id;
        this->name=obj.name; 
        if(this->ptr!=nullptr)
        {
            delete this->ptr;
            ptr=nullptr;

        }
        if(obj.ptr){
             this->ptr=new int(*obj.ptr);

        }
        std::cout << "Hi From Operator= copy overload " << std::endl;
        return *this;
    }

    /*Move Constructor uses std::move to convert from lvalue to rvalue 
    right value &&refrence is used as argument to differentiate between move & copy */
    Test(Test &&obj)
    {
        this->id=obj.id;
        obj.id=0;
        this->name=obj.name; 
        obj.name="";
        if(this->ptr!=nullptr)
        {
            delete this->ptr;
            ptr=nullptr;
        }
        
        if(obj.ptr){
            this->ptr=obj.ptr;
            obj.ptr=nullptr;
        }
        std::cout << "Hi From Move Constructor " << std::endl;


    }

/*Move operator overload*/

    Test &operator=(Test&&obj)
    {
        this->id=obj.id;
        obj.id=0;
        this->name=obj.name; 
        obj.name="";
        if(this->ptr!=nullptr)
        {
            delete this->ptr;
            ptr=nullptr;

        }
        if(obj.ptr){
             this->ptr=obj.ptr;
            obj.ptr=nullptr;

        }

        std::cout << "Hi From Operator= Move overload " << std::endl;
        return *this;
    }



    /*Destructor*/
    virtual ~Test()
    {
        if(this->ptr!=nullptr)
        {
            delete ptr;
        }
        std::cout << "Bye From Destructor" << std::endl;


        /*to check memory leakage : valgrind --leak-check=full ./a.out*/
    }


    /*Implementation of Methods better be outside the class to be detected in .text if they are not used */
    /*in case all code in same place ***/


    /*cant use "this" ptr to static member function just static members*/
    static Test* objPtr();
    
    
    int modify() const;
    void getter();
    void setter(int id1,std::string name1,int*ptr1);


    /*Friend method : function not related to class but it can access private members of class*/

    friend void friendMethod(const Test&obj);

    /*Virtual function*/

    virtual void vfun()
    {
        std::cout << "Hi from Base virtual function" << std::endl;
        
    }

    /*public members*/
    static int val1;
    int n1{};
    int n2{};
    int n3{};
    private:
        /*Friend class can access private/protected members*/
        friend class MyClass;

        int id{};
        std::string name{};
        int *ptr=nullptr;

        /*static members must be initialized outside , if constant so no problem*/
        static Test* objptr;
        const static int val2=10;
        mutable int val3{};
        const int number1 =20;
        static int val4;


};
/*Static members initialization*/
Test* Test::objptr=nullptr;
int Test::val1{};
int Test::val4{};


/*Const function changes only static / mutable members*/
/*const Instance/Object can only access const/static methods but if normal Instance can access all methods */
int Test::modify()const 
{   
    this->val1=5; /*static member*/
    std::cout << this->val2 << std::endl; /*constant*/
    val3=10; /*mutable member*/
    std::cout << this->id << std::endl; /*normal int*/
return 0;
}


void Test::getter()
{
    std::cout << this->id <<" "<< this->name <<" "<< this->ptr << " val:"<<val4<<" "<<     (this->ptr != nullptr ? *(this->ptr) : 0)  << std::endl;
}

void Test::setter(int id1,std::string name1,int*ptr1)
{
    this->id=id1;
    this->name=name1;
    if(this->ptr!=nullptr)
    {
            delete this->ptr;
            this->ptr=nullptr;

    }
    this->ptr=ptr1;

}

/*cant use this ptr to static member function just static members*/

Test* Test::objPtr()
{
    
    static Test obj1;
    if(objptr==nullptr)
    {
        objptr=&obj1;

    }
    return objptr;
}



/*Friend Method to Class*/
void friendMethod(const Test&obj)
{
    std::cout << obj.val2 << std::endl;
}


 class MyClass
 {
 public:
    MyClass(){};
    void myFun()
    {
        Test t9(1,"friend",new int(10));
        std::cout << t9.name << std::endl;
        t9.getter();
    }
    ~MyClass(){};
 private:
    
 };


/*Inheritance "is a " relationship*/

/*Multi level inheritance as example*/
/*Test > test0>test 1 Constructors will be called*/
class Test0 : public Test
{
    public:
    Test0(int num):num1(num){std::cout << "Hello from Test0" << std::endl;}
    
    int num1{};


    ~Test0()=default;


};

class Test1 : public Test0
{   
    public:
    Test1(int num):Test0(num){std::cout << "Hello from Test1" << std::endl;}

    int num2=num1;
    
        void vfun() override
    {
        /*members of inherited class can be modified inside functions*/
        n1=10;
        std::cout << "Hi from Derived class virtual function" << std::endl;
    }   

    ~Test1()=default;

};

/*Single inheritance*/
class Test2 : public Test
{
    public:
   Test2(int id,std::string name,int*ptr):Test(id,name,ptr){}

    void vfun()
    {
        std::cout << "Hello from Drived virtual function" << std::endl;
    }

    ~Test2()=default;


};



/*Abstract class | interface*/
class Test3
{
    public:

    /*Pure Virtual function should be assinged =0 */
    virtual void pureFunction()=0;


    virtual ~Test3(){std::cout << "Hi from Test3 Destructor" << std::endl;}



};

class Test4 : public Test3
{
    public :

    Test4(){}

    void pureFunction() override
    {
        std::cout << "Hi from virtual pure function" << std::endl;
    }

    ~Test4(){std::cout << "Hi from Test4 Destructor" << std::endl;};



};


class Test5
{   
    public:

    Test5(){std::cout << "Test5 const" << std::endl;}
    int number5{};
     virtual void test(){};
     virtual ~Test5(){std::cout << "Test5 Dest" << std::endl;}

};

class Test6:public Test5
{
     
    public:
    int x{};
    int y{};
    Test6(){std::cout << "Test6 const" << std::endl;}
    Test6(int x,int y):x(x),y(y){}


    /*pointer copy const */
    /*more instruction as derefrencing occurs , can cause risk of nullptr to be passed */
    Test6(const Test6 &obj)
    {
        this->x=obj.x;
        this->y=obj.y;

    }

    int number6{};
    ~Test6(){std::cout << "Test6 Dest" << std::endl;}
};


typedef  void(*fptr)(const Test &);

int main(int argc, const char** argv) {
     
    Test t0; /*Default*/
    Test t1(1,"som3a",new int(8)); /*Initializer list */
    std::cout << &t1 << std::endl;

    Test t2(t1);    /*Copy*/
    std::cout << &t2 << std::endl;
    Test t3;
    t3=t2;  /*Overload = */
    std::cout << &t3 << std::endl;
    t3.getter();
    std::cout << "/* message */" << std::endl;
    Test t4(std::move(t3));

    t1.getter();
    Test t5;
    t5=std::move(t1);

    t0.getter();
    t1.getter();
    t2.getter();
    t3.getter();
    t4.getter();
    t5.getter();

    Test::objPtr()->setter(2, "ss", new int(4));
    Test::objPtr()->getter();

    Test::objPtr()->modify();
    std::cout <<  Test::objPtr()->val1<< std::endl;

    const Test t6;
    t6.modify();

    /*Acessing private members of Test Class using Friend*/
    MyClass t7;
    t7.myFun();

    /*Friend Method accessing private members  of a class*/

    friendMethod(t6);



    /*Multilevel inheritance */
    Test1 t8(2);
    std::cout <<     t8.num2 << std::endl;
    
    

    /*ptr will access any member of type Test*/
    /*Better to do that with abstract / interface class*/
    /*Full abstract class  cant make any instance from it directly*/
    Test *ptr=new Test1(69);
    /*polymorphism  as there will be dynamic binding , vfun in Test1 class will be called*/
    ptr->vfun();
    
    delete ptr;

    /*For Dynamic binding and RAII using smart pointers is good choice*/

    std::unique_ptr<Test> uniqPtr= std::make_unique<Test2>(69,"som3a",new int(5));
    uniqPtr->vfun();

    /*Cannot create an instance from abstract class*/
    // Test3 t10;


    /*ptr will have a vtable pointer that points to Test4 virtual functions*/
    /*using gdb examine the vtable address  x/32a [vtable address */ 
    std::unique_ptr<Test3> ptr1= std::make_unique<Test4>();
    ptr1->pureFunction();


    /*as there's no override function in Test6 class so "_vptr.Test5 = 0x555555557d00 <vtable for Test6+16>"vtable of Test6 will points to Test5::test() */
    Test5 *ptr2=new Test6();
    ptr2->number5;
    
    
    delete ptr2;

    /*testing copy constructor using pointer*/
    Test6 t10;
    t10.Test5::test();
    Test6 t11(t10);
    std::cout << t11.x << std::endl;
    // Test6 t12(nullptr); /*segmentation fault risk o.o*/
    fptr pt1=&friendMethod;

    (*pt1)(t0);

    std::cout  << std::endl;

    /*Dynamic cast */
    Test5 *ptr3=new Test6();
    Test6 * ptr4= dynamic_cast<Test6*>(ptr3) ;
    /*POINTER now can points to any member of base or derived class*/
    ptr4->y;
    // delete ptr3;
    delete ptr4; /*segemntation fault ?*/
    




    return 0;
}
/*

dynamic_cast: Ensures basePtr is actually a Derived object at runtime.
static_cast: Assumes basePtr is Derived without checking.
reinterpret_cast: Converts any pointer to another type, useful for low-level operations but risky.

*/

/*if other class inherited form other an virtual destructors exist or no ,all constructors will be destructed [if ptr to same type or direct object creation] , But if we have a ptr to base = new Derived so we should add virtual to base dest to ensure the derived is destructed too */



/*****************NOTES******************* */

/*polymorphic class : normal class with at least one virtual function / virtual distructor can be overriden 
designed to be a base class for other classes*/

/*Abstract class / interface class is an abstraction class with only pure functions and virtual destructor with no constructor,
 designed to be a base class for other classes  ,cannot make an object from it*/

/*if base is virtual  so Derived will be destrucd then base*/
/*to ensure resource clean up*/

/*cant use this ptr to static member function just static members*/


/*cout << f%f   gives an error */

/*constructor : initialize object*/
/*C++ adapted bottom-up*/
/*static method cant be const */
/*functions should be defined if they are used to avoid linker error*/
/*default argument if in function prototype so no need in function definetions as it will give error*/
/*pure virtual functions in abstract class must be defined in derived classes*/

/*virtual functions can be overloaded and overriding*/
/*cannot initialize and arry with ref as ref should be initialized */

/*printf  associativity is compiler dependent but with gcc from right to left */
/*cout from left to right*/


/*main cannot take default argument as the right arg is an arr*/

/*trailing argument from right to left*/


/*****General Notes*** */

/*
    int x1=90;
    int *lol=&x1;
    std::cout << *lol << std::endl;

    delete lol; //Cant delete area from stack
    */

/*By default, all the files in C++ are opened in text mode. They read the file as normal text.*/

/*Using & on a register variable may be invalid, since the compiler may store the variable in a register*/

/*class is private by default*/

/*
    static int a = 5;
	auto check = [=]() 
        {
		a = 10;   
	};
    a val will be 10 , if a not static we shpuld add mutable keyword but value for a will be localy inside lamda
    */


/* C++ input and output are type safety that means we don’t need to specify the type of variable we are printing.*/


/*any thing in stack can be changed even if const by doing const_cast but the val itself will not be changed as it will be moved to register and when getting val again it will be same but ptr val will be changed */
/*const global/static  segementation fault as it 's in .rodata*/
/*reinterpet cast from higher to lower pointer casting*/


/*switch/if/if with conxtexpt with initializer c++17*/


/*GDB*/
/*
stat
ctrl+x+a to  see the code when using gdb

gdb a.out
start   n for next
set demangle-style auto   | set print asm-demangle on | set print pretty on
p &d2   > address of d2

x/32 address   to see the stack x > examine memory /32 to convert hex to decimal in memory

*/