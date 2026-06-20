#include <iostream>
using namespace std;

class Data{
    int Id;
    public:
        string Name;
        char Phone[10];
        string Address;
};
class Student:public Data{};
class Teacher:public Data{};
class Accountant{
    int Id;
    public:
        string Name;
        char Phone[10];
        string Address;
};
class Manager{
    public:
        void EnterDetails(Data* d){
            cout << "ENTER THE NAME: ";
            cin >> d->Name;
            cout << "ENTER THE PHONE NO. : ";
            cin >> d->Phone;
        }
        void EnterDetails(Accountant* d){
            cout << "ENTER THE NAME: ";
            cin >> d->Name;
            cout << "ENTER THE PHONE NO. : ";
            cin >> d->Phone;
        }
        void PrintDetails(Data* d){
            cout << "NAME: " << d->Name << endl << "PHONE NO.: " << d->Phone << endl;
        }
        void PrintDetails(Accountant* d){
            cout << "NAME: " << d->Name << endl << "PHONE NO.: " << d->Phone << endl;
        }
};
int main(){
    Manager* entries = new Manager();
    Teacher* t = new Teacher();
    Student* s = new Student();
    Accountant* a = new Accountant();
    entries->EnterDetails(t);
    entries->PrintDetails(t);
    entries->EnterDetails(a);
    entries->PrintDetails(a);
    entries->EnterDetails(s);
    entries->PrintDetails(s);
}
