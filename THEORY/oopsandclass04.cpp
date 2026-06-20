#include <iostream>
using namespace std;
class Syllabus{
    public:
        string subjects[10];
};

class Course{
    int Id;
    public:
        string topic;
        Syllabus* content;
        Course(int Id, string Name){
            this->Id = Id;
            this->topic = Name;
        }
        int getId(){
            return Id;
        }
};

class Student{
    int rollNo;
    string name;
    public:
        Course* mycourse;
        Student(int rollNo, string name){
            this->rollNo = rollNo;
            this->name = name;
        }
        int GetrollNo(){
            return rollNo;
        }
        string Getname(){
            return name;
        }
        void Setname(){
            name = name;
        }
};

int main(int argc, char const *argv[])
{
    Course* c1 = new Course(1200, "JAVA");
    Student* s1 = new Student(1,"ATHARV");
    s1->mycourse = c1;
    cout << "| ROLL NO.: " << s1->GetrollNo() << "| NAME: " << s1->Getname() << "|\n";
    cout << "| COURSE NAME: " << c1->topic << "| COURSE ID: " << c1->getId() << "|\n";
    return 0;
}
