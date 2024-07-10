#include <cstddef>
#include <cstdlib>
#include <iostream>

class Data
{
    private:
    Data(){}
    //-
    public:
    int x=100; //+ 
    static int y ;
    static Data*instance;


    
    static Data &getInstance()
    {
      
        static Data ob1;
    
        return ob1;
    }

    static Data *instancePTR()
    {
        if(instance==nullptr)
        {

            instance=&Data::getInstance();
            // static Data obj;
            // instance=&obj;
            // instance = (Data*)malloc(sizeof(Data));
            // instance=new Data();
        }
        return instance;
    }
    ~Data(){
        
        std::cout << "Des" << std::endl;
    }

};
int Data::y=10;
Data* Data::instance=nullptr;
int main()
{



std::cout <<Data::instancePTR()->x << std::endl;


}
