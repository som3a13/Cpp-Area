#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <string.h>
#include <sstream>
#include <system_error>
#include <utility>
#include <vector>
#include <list>
#include <deque>

#include <map>
template <typename  T> T print(T x)
{
    std::cout << x << std::endl;
    return x;
}

struct data
{
    int x;
    int y;
};
int main(int argc, const char** argv) {



    /*Std::string*/

    std::string s1("Hello" "World");
    
    /*concatination */
    using namespace std::literals::string_literals; 
    std::string s3 = "Hello"s + "World"; /* convert Hello to string */
    std::cout << s3 << std::endl;

    std::string s4 =  "MOhamed";
    s4.append(s1);
    std::cout << s4 << std::endl;

    s4 +=s3;
    
    std::cout << s4 << std::endl;

    /*insert*/
    s4.insert(3,"lol");
    std::cout << s4 << std::endl;

    /*search*/

    auto it =s4.find("z");
    if(it!=std::string::npos)
    {
            std::cout << it << std::endl;

    }

    /*new sub string*/

    std::string sub = s4.substr(10,5);
    std::cout << sub << std::endl;

    /*size / length*/
    std::string s5 = "Hello";
    std::cout <<     s5.size()<< std::endl;
    std::cout <<     s5.length()<< std::endl;
    /*std::size works with c++17*/
    std::cout << std::size(s5) << std::endl;
    std::cout <<     strlen(s5.c_str())<< std::endl;
    
    /*no need to check for null terminator*/
    for (size_t i=0;s5[i]!='\0';++i) 
    {
        std::cout <<         s5[i] << std::endl;
    }
    int i=0;
    while(i<s5.size())
    {
        std::cout << s5[i] << std::endl;
                i++;

    }    
    i=0;
    while(s5[i]!='\0')
    {
        std::cout << s5[i] << std::endl;
                i++;

    }  
 
    /*Raw string*/
    std::string s6 = R"...(/home/som3a313/)...";
 
    std::cout << s6 << std::endl;
    
    std::string frame{"som3a 123 10"};
    std::string name;
    int ID,num;
    std::stringstream s(frame);
    std::getline(s,name,' ');
    s >> ID>>num ;
    std::cout << num <<" "  << ID << std::endl;
    std::string input;
    // std::getline(std::cin , input);
    // std::cout << input << std::endl;
    
    /*convert string to c_str*/
        std::string s7{"lol"};
        
        char*ptr = const_cast<char*>(s7.c_str());

         ptr[0]='a'; 

         std::cout << s7 << std::endl;



    /*STL*/
    /*
        1- Containers : Data structures to store Data
        2- Algorithms : perform operations on data
        3- iterators : pointers to the data to mainpulate 
    
    
    */

    /*
    Containers*/

    /*Std::array   static memory allocation*/

    int arr1[]={50,23,5,5,6,199,0};
    
    std::sort(&arr1[0],&arr1[(std::size(arr1))],[](int x,int y)
    {
        return x<y;
    }); /*.end : element after the end*/
    // std::sort(std::begin(arr1),std::end(arr1));
    for(auto &i : arr1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    constexpr int x=6;
    std::array<int, x> arr{1,99,9,8,1};

    std::cout << arr.size()<< std::endl;    

    /*arr.end() points to empt place at end of array */
    try  {
        int i{8};
        if(&arr[i]<std::end(arr)){
             std::cout << arr[i] << std::endl;

        }
        else
        {
            throw std::runtime_error("error");

        }
    }
    catch  (const std::exception& ex) 
    {
                std::cerr << "Exception caught: " << ex.what() << std::endl;
    }







    /*std::vector        dynamic memory allocation*/
    std::vector<int> v{12,24,1,1,1};
    v.insert(v.end(),100);
        for(auto &i : v)
    {
        std::cout << i << " ";
    }
    std::cout <<std::endl;
        
    auto count = std::count_if(v.begin(), v.end(),[](const auto &element){
        return element <10;
    });

    std::cout << "Count numbers less than 10:"<<count << std::endl;

    std::vector<int> v2(2,4);
    auto it1= std::find(v.begin(),v.end(),12);
    if(it1!=v.end())
    {
        std::cout << *it1 << std::endl;
    }

    /*emplace back : push from back more than value but should use initializer list*/
    // std::vector<std::initializer_list<int>> vec{};
    // std::initializer_list<int>l{2,2,3,4};
    // vec.emplace_back(l);



    /*vector pair*/
    std::vector< std::pair<std::string,int>>v1{{"som3a",1},{"moe",2}};
    v1.emplace_back("ss",5);   
    
    for(auto i=v1.begin();i!=v1.end();i++)
    {
        std::cout << i->first<<" " << i->second << " ";
    }


    std::pair<std::string, int> p1{"lol",1};
    v1.emplace_back(p1);
    std::cout << v1[3].first << " " << v1[3].second << std::endl;
    /*std::find/max_element return a pointer to the element */
    auto it2 = std::find_if(v1.begin(),v1.end(),[](const auto & element)
    {
        return element.first =="lol";
    });
    /*std::distance return int position*/
    int index = std::distance(v1.begin(), it2);
    std::cout << index << std::endl;

    data d{1,2};
    data d2{3,5};

    std::vector<data> d1{};
    // d1.emplace_back(1,2); /*need constructor in the struct*/
    d1.push_back(d);
    d1.push_back(d2);
    

    for(auto &i : d1)
    {
        std::cout << i.x << " "<< i.y << " ";
    }



    /*std::deque*/


    /*push / pop from back or front ,memory wise bad */
    std::deque<int> deq{1,2,3,4,5,6};

    /*std::list  double linked list*/
    /*can push/pop  from front or back  good for insertion randomly */

        std::list<int> l1{1,2,3,99,4,5,6};

        auto it3=l1.begin();
        std::advance(it3,2);
        std::cout << *it3 << std::endl;
        it3=l1.begin();
        std::advance(it3,3);
        std::cout << *it3 << std::endl;

    /*std::set  ordered set using key binary tree */
    /*no element access*/



    /*map*/
    std::map<int,std::string> m1{};
    m1[1]="s";
    // m1={{1,"s"},{2,"m"}};
    



    return 0;       
}

