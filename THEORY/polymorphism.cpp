#include <iostream>
using namespace std;
class Creatures{
    public:
    virtual void eat() = 0;
    virtual void talk() = 0;
    virtual void walk() = 0;
};

class Animals:public Creatures{};

class Humans :public Animals{

    void eat(){
        cout << "EAT WITH THEIR HANDS"<<endl;
    }
    void talk(){
        cout << "SPEAKS HUMANOID LANGUAGE"<<endl;
    }
    void walk(){
        cout << "WALK ON TWO FEET"<<endl;
    }
};

class Dog :public Animals{

    void eat(){
        cout << "EAT WITHOUT THIER HANDS"<<endl;
    }
    void talk(){
        cout << "BARKS"<<endl;
    }
    void walk(){
        cout << "WALK ON FOUR FEET"<<endl;
    }
};

class Birds:public Creatures{
      
};

class Crow:public Birds{
   void eat(){
        cout << "EAT WITH THE BEAK "<<endl;
    }
    void talk(){
        cout << "CHIRP"<<endl;
    }
    void walk(){
        cout << "FLY"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Animals* ptr = new Humans();
    ptr->eat();
    ptr = new Dog();
    ptr->eat();
    return 0;
}