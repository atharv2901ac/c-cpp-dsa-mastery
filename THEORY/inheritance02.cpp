#include <iostream>
#include <vector>
using namespace std;
 
class Shape{
    public:
    virtual void CalculateArea(float l,float b){}
    virtual void CalculateArea(int r){}
    virtual void CalculateArea(int h, int b){}
};

class Rectangle:public Shape{
    public:
        virtual void CalculateArea(float l,float b){
            float area = l * b;
            cout << "AREA OF RECTANGLE IS " << area << endl;
        }
};
 
class Triangle:public Shape{
    public:
        virtual void CalculateArea(int h, int b){
            int area = (h * b)/2;
            cout << "AREA OF TRIANGLE IS " << area << endl;
        }
};
 
class Circle:public Shape{
    public:
        virtual void CalculateArea(int r){
            int area = 3.14 * r * r;
            cout << "AREA OF CIRCLE IS " << area << endl;
        }
};

int main(int argc, char const *argv[])
{
    Shape* rect = new Rectangle();
    Shape* circ = new Circle();
    Shape* tri = new Triangle();
    rect->CalculateArea(20,30);
    tri->CalculateArea(20,60);
    circ->CalculateArea(10);
    return 0;
}
