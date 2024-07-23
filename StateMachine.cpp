#include <chrono>
#include <iostream>
#include <map>
#include <thread>

/*Connect =Disconnect,Fetch*/
/*Fetch = idle , Download*/
/*Download = Update , idle*/
/*Disconnect = IDLE*/
/*IDLE = connect*/
/*Connect > fetch > download > update >  disconnect >idle*/




enum class States : unsigned char
{
    CONNECT,
    DISCONNECT,
    FETCH,
    DOWNLOAD,
    UPDATE,
    IDLE
};

enum class Go_to : unsigned char
{
    GO_CONNECT,
    Go_DISCONNECT,
    Go_FETCH,
    Go_DOWNLOAD,
    Go_UPDATE,
    Go_IDLE
};



class SoftwareUpdate
{
    public:

    States currentState=States::IDLE;


    SoftwareUpdate()
    {
        mymap[States::CONNECT]={{Go_to::Go_DISCONNECT,States::DISCONNECT},{Go_to::Go_FETCH,States::FETCH}};
        mymap[States::DISCONNECT]={{Go_to::Go_IDLE,States::IDLE}};
        mymap[States::FETCH]={{Go_to::Go_IDLE,States::IDLE},{Go_to::Go_DOWNLOAD,States::DOWNLOAD}};
        mymap[States::DOWNLOAD]={{Go_to::Go_UPDATE,States::UPDATE},{Go_to::Go_IDLE,States::IDLE}};
        mymap[States::UPDATE]={{Go_to::Go_DISCONNECT,States::DISCONNECT},{Go_to::Go_IDLE,States::IDLE}};
        mymap[States::IDLE]={{Go_to::GO_CONNECT,States::CONNECT}};


    }
    
    

    void update()
    {   

        while(1)
        {

         switch(currentState)
        {

            case States::IDLE : currentState=mymap[currentState][Go_to::GO_CONNECT];


                                std::cout <<  " connect" << std::endl;;


                                break;
            case States::CONNECT : currentState=mymap[currentState][Go_to::Go_FETCH];

                                std::cout <<  " fetch" << std::endl;


            break;

            case States::DISCONNECT : currentState=mymap[currentState][Go_to::Go_IDLE];
                                        std::cout <<  " IDLE" << std::endl;

            break;

            case States::UPDATE : currentState=mymap[currentState][Go_to::Go_DISCONNECT];

                            std::cout <<  " Disconnect" << std::endl;

            break;

            case States::FETCH : currentState=mymap[currentState][Go_to::Go_DOWNLOAD];

                        std::cout <<  " Download" << std::endl;

            break;

            case States::DOWNLOAD : currentState=mymap[currentState][Go_to::Go_UPDATE];
                    std::cout <<  " Update" << std::endl;



            break;
            
            default:            break;


        }
                    std::this_thread::sleep_for(std::chrono::seconds(1));

        }
   





    }



    ~SoftwareUpdate(){};

    private :
        std::map<States,std::map<Go_to, States>> mymap;

};  



int main(int argc, const char** argv) {
    
    SoftwareUpdate s1;
    std::cout << int(s1.currentState) << std::endl;;
    s1.update();
    

 
 
    return 0;
}