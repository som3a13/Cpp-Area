#include <iostream>
#include <memory>
//PROTECTED BASE , DRIVED
class Shape {
private:
    int width;
    int radius;
    
public:

    int length;
    virtual void draw()=0; // Pure function
    Shape() {}
    virtual ~Shape() {}
};

class circle : public Shape {
    private:
    circle(){} 
    friend class control;
    public:
        
              
    
    void draw() override {
        std::cout << "Draw Circle" << std::endl;
    }
    ~circle() {}
};

class rectangle : public Shape {
    private:
    rectangle(){}
    friend class control;

public:
    void draw() override {
        std::cout << "Draw Rectangle" << std::endl;
    }
    ~rectangle() {}
};




class control
{
    public:
    Shape*ptr;
     rectangle rec;
     circle cir;
    typedef enum  // no scope for it required
    {
        CIRCLE,
        RECTANGLE
    }figure;
    // enum class figure
    // {
    //     CIRCLE,
    //     RECTANGLE
    // }
    //  figure shape;
    // control(figure shape):shape(shape){
     
    // }
    figure shape;
    Shape *cDraw(const figure &shape)
    {    
        
        switch(shape)
        {
            case figure::CIRCLE :ptr=new circle();
            break;
            // case figure::RECTANGLE:ptr=new rectangle;
            case figure::RECTANGLE:ptr=&rec;
            break;
        }
        return ptr;
    }
    ~control(){
        // delete ptr; error cuz instance are static
    }
};
// with unique pointer it gives error to access of derived constructor


int main() {
    control ctrl; // using temp instance expire the ptr
    Shape *ptr=ctrl.cDraw(control::RECTANGLE);
    ptr->draw();
    // control(control::figure::CIRCLE).cDraw()->draw();
    // control(control::figure::RECTANGLE).cDraw()->draw();

    return 0;
}
