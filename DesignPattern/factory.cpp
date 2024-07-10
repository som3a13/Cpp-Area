#include <iostream>
#include <memory>

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
    friend class control;
    public:
        
               
    
    void draw() override {
        std::cout << "Draw Circle" << std::endl;
    }
    ~circle() {}
};

class rectangle : public Shape {
    private:
    
    friend class control;

public:rectangle() {}
    void draw() override {
        std::cout << "Draw Rectangle" << std::endl;
    }
    ~rectangle() {}
};

// void disp(Shape &obj) {
//     obj.draw();
// }


class control
{
    public:
    std::unique_ptr<Shape>ptr;
    enum class figure
    {
        CIRCLE,
        RECTANGLE
    };
     figure shape;
    control(figure shape):shape(shape){
     
    }
    void cDraw()
    {   
        switch(shape)
        {
            case figure::CIRCLE :ptr=std::make_unique<circle>();
            ptr->draw();
            break;
            case figure::RECTANGLE:ptr=std::make_unique<rectangle>();
            ptr->draw();
            break;
        }
    
    }
    ~control(){}
};



int main() {
    
    control a(control::figure::CIRCLE);


    return 0;
}
