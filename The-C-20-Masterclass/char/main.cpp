#include <cctype>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, const char** argv) {







    // char msg2[]{"HELLO"};
    // std::cout << (std::isalnum('9'))<< std::endl;
    // std::cout << msg2 << std::endl;
        const char* msg = "hello, world! 123"; // String to check

    std::cout << "Character checks:\n";
    for (int i = 0; msg[i] != '\0'; ++i) {
        std::cout << "Character: " << msg[i] << " - isalnum: " << std::isalnum(msg[i]) << '\n';
    }
    //isalpha , isalnum , isdigit , isupper , islower
    
    // std::string msg4{"TEST"};
    //    std::transform(msg4.begin(), msg4.end(), msg4.begin(), [](unsigned char c) {
    //     return std::tolower(c);
    // });
    // std::cout << msg4 << std::endl;
    char msg5[]={9,9,'A'};
    // std::cout <<reinterpret_cast<int*>(msg5[2]) << std::endl;
        std::cout << static_cast<int>(msg5[1]) << std::endl;
    
    //EX

    /*
    #include <iostream>
#include "exercise.h"


void find_stuf_out( char data[] , unsigned int size){

    unsigned int vowel_count{};
    unsigned int consonant_count{};
    
    //Don't modify anything above this line
    //Your code should go below this line
       
                  for (int i = 0; data[i] != '\0'; ++i) {
        data[i] = std::tolower(data[i]);
    }
    char vowel[]{'a','e','i','o','u'};
    bool isVowel{false};
for(unsigned int i{}; i < size; ++i){

        isVowel = false;
     if(std::isalpha(data[i])){
         for(std::size_t j{0};vowel[j]!='\0';j++){
            if(data[i]==vowel[j])
            {
                ++ vowel_count;
                isVowel=true;
                break;
            }
         }
         if(!isVowel)
         {
            ++consonant_count;

         }
         
        }

    }
   std::cout << "The string contains " <<vowel_count << " vowels" << " and " << consonant_count << " consonants";
        
    //Your code should go above this line
    //Don't modify anything below this line
}*/
char msg1[] {"The sky is blue my friend.E"}   ; 
for(auto& i : msg1)
    {
        if(std::isblank(i))
        {
            std::cout << "/* message */" << std::endl;
            i='_';
        }
    }
    std::cout << msg1 << std::endl;
    
    //EX 
    /*
    
    char * result{nullptr};
    
    //Don't modify anything above this line
    //Your code will go below this line
    
    //REMEMBER : WHEN YOU DYNAMICALLY ALLOCATE FOR SPACE FROM THE HEAP, YOU HAVE TO ACTIVELY RELEASE THAT TO THE
    //SYSTEM WHEN DONE WITH IT. BE A GOOD C++ CITIZEN!
    result = new char[size];
    for(unsigned int i{} ; i<size;i++)
    {   
        if(isblank(data[i]))
        {
            // data[i]='_';
            result[i]='_';

        }
        else
        {
            result[i]=data[i];
        }
    }
    std::cout << "After replacing the spaces, we get : " << result;
    */

    for(std::size_t i{};msg1[i]!='\0';i++)
    {
        std::cout << msg1[i] << std::endl;
    }
    
    std::string som3a{"He'l'l""o"};
    
    std::cout << som3a << std::endl;



     const char* original = "Aello";
    char* msg3 = new char[strlen(original) + 1]; // Allocate memory dynamically
    strcpy(msg3, original); // Copy the string literal to the dynamically allocated memory
    
    std::cout << "Original message: " << original << std::endl;
   const char* msg4="Bello";
    // msg4[0]='l';
    // std::cout << msg4 << std::endl;
    msg3[0] = 'H'; // Modify the first character
    std::cout << "Modified message: " << msg3 << std::endl;
    std::cout <<     &msg3<< std::endl;    
    std::cout <<   std::dec<<static_cast<int>( std::strcmp(original,msg4))<< std::endl;
    delete[] msg3; //
    std::string msg6[]{"Zello","World13","l"};
    // std::cout << msg6[2][0]<< std::endl;
        int max{};
        std::string result{};
    for(std::size_t j;j<3;j++){
        int count{};

        for(auto i : msg6[j])
    {
        // std::cout << i << std::endl;
        count++;
    }
        std::cout << count << std::endl;
        if(count>max)
        {
            max=count;
            result=msg6[j];
        }

    }
    std::cout << result << std::endl;
    std::cout << (msg6[0]>msg6[1]) << std::endl;
    result.c_str();
    std::cout << result << std::endl;
    std::string som3a1{};
    using namespace std::string_literals;
    som3a1= "som3a"s + "world";
    std::cout << som3a1 << std::endl;
    return 0;


}
