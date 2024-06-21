#include <ios>
#include <iostream>
#include <bitset>



void op(unsigned char flag)
{
    std::cout << ((flag & (1<<1))>>1)<<std::endl;
}


int main(int argc, const char** argv) {
    

    // converting 
    int data=100;
    std::cout <<std::bitset<8>(data)<<  std::endl;
    std::cout << std::hex  <<std::showbase<<data<< std::endl;
    std::cout << std::oct << std::showbase<< data<< std::endl;


    //shifting

    data = data >>2; // shift right divides by 2^n - shift left multiply 2^n
    std::cout << std::dec<< (data)<< std::endl;

    std::cout <<  std::bitset<8>(data)<< std::endl;

    //set bit
    data |=(1<<7);
    std::cout <<  std::bitset<8>(data)<< std::endl;
    //clear bit
    data &=~(1<<0);
    std::cout <<  std::bitset<8>(data)<< std::endl;
    //toggle bit
    data ^=(1<<0);
    std::cout <<  std::bitset<8>(data)<< std::endl;

    unsigned short val {0xff0u};
    std::cout <<  val<< std::endl;
    val=static_cast<unsigned short>(val << 1);
    std::cout <<  val<< std::endl;
    std::cout <<  std::bitset<16>(val)<< std::endl;

    //XOR
    val^=1;
    std::cout <<  std::bitset<16>(val)<< std::endl;

    std::cout << val << std::endl;
    //NOT ~  OR | AND &




    // Checking position
    int z= 20;
    std::cout << std::bitset<16>(z) << std::endl;
    if((z&(1<<2) )>>2) // ((z>>2) & 1)
    {
        std::cout << "bit 2 =1" << std::endl;
    }

    op(2);

    
    //error 
    // double val1{15.4};
    // val1 =val1>>2;
    return 0;
}