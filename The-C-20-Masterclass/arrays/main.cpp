#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ctime>
int main(int argc, const char** argv) {

    int arr[]{1,2,3,4,5,6};
    //c++17
    std::cout << std::size(arr) << std::endl;
    char message[]={"Hello"};

   message[0]=std::tolower(message[0]);
    std::cout << message << std::endl;


    //Generate random numbers each time
    std::time(0);
    std::srand(time(0));
    int data = std::rand() %12; // range 0-11
    std::cout << data << std::endl;



    //EX
    int data1[]{1,2,3,4,5,6,9};
    int data2[]{3,8,4,5,6,7,8};
    unsigned int size = 7;
  unsigned int counter{};
  int arr_common[10]{};
//   std::cout <<  "There are 3 common elements they are : ";
for(std::size_t i=0;i<size;++i)
  {
      for(std::size_t j=0;j<size;j++)
      {
          if(data1[i]==data2[j])
          {
            arr_common[counter++]=data1[i];
            // std::cout <<  data1[i] << " ";
          }
      }

  }
  if(counter==0)
  {
          std::cout <<"There are " << counter << " common elements" ;

  }
  else
  {
    std::cout <<"There are " << counter << " common elements they are : " ;
    for (std::size_t i{};i<counter;i++) {
        /* code */
        std::cout << arr_common[i] << " ";
    }
  }
    // std::cin.getline()
    return 0;


}
