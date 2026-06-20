#include <iostream>
#include <vector>
using namespace std;
class Syllabus{
    public:
        vector <string> topics;
};
class Subject{
    int id;
    string name;
    public:

        Syllabus syllabus;
        Subject(int id, string name){
            this->id = id;
            this->name = name;
        }
};

class Course{
    int Id;
    
    public:
        string topic;
        vector <Subject*> content;
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

class CourseManager{
    vector <string> CourseList;
    public:
        void CreateNewCourse(){
            string name;
            cout << "ENTER COURSE NAME: ";
            cin >> name;
            Course* course = new Course(CourseList.size()+1,name);
            cout << "TO SAVE A COURSE YOU MUST ATLEAST ADD ONE SUBJECT......" << endl;
            cout << "ENTER SUBJECT NAME: ";
            cin >> name;
            Subject* subject = new Subject(course->content.size()+1, name);
            cout << "TO SAVE A SUBJECT YOU MUST ATLEAST ADD ONE TOPIC......." << endl;
            cout << "ENTER A TOPIC NAME: ";
            cin >> name;

            subject->syllabus.topics.push_back(name);
            course->content.push_back(subject);
        }
        void PrintCourseDetails(int id){

        }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

