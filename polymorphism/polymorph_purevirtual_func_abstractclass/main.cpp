#include <iostream>
#include <vector>

using namespace std;

class Shape // abstract Base class
{
private:
    // attributes common to all shapes
public:
    virtual void draw() = 0;   // pure virtual function
    virtual void rotate() = 0; // pure virtual function
    virtual ~Shape()
    {
    }
};

class Open_Shape : public Shape // abstract class
{
public:
    virtual ~Open_Shape()
    {
    }
};

class Closed_Shape : public Shape // abstract class
{
public:
    virtual ~Closed_Shape()
    {
    }
};

class Line : public Open_Shape // concrete class
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line()
    {
    }
};

class Circle : public Closed_Shape
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle()
    {
    }
};

class Square : public Closed_Shape
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square()
    {
    }
};

void screen_refresh (const std::vector<Shape *> &shapes)
{
    std::cout << "Refreshing" << std::endl;
    for (const auto p:shapes)
        p->draw();
}

int main(int argc, char** argv)
{
   // Shape s;                              // Compiler error
   // Shape *p = new Shape ();  // Compiler error
   // Circle c;        
  //  c.draw ();       //this is ok however we are using static binding not base class pointer
  
//  Shape *ptr = new Circle ();
//  ptr ->draw ();        // this is using dynamic binding
//  ptr -> rotate ();
    // delete ptr;
    
    Shape *s1 = new Circle ();
    Shape *s2 = new Line ();
    Shape *s3 = new Square ();
    
    std::vector <Shape *> shapes {s1, s2, s3};
//    for (const auto p:shapes)
//        p->draw ();

    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
  
  
  
  
   
   
    return 0;
}
