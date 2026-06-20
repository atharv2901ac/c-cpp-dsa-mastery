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
        string GetName(){
            return name;
        }
};

class Course{
    int Id;
    
    public:
        string topic;
        vector <Subject*> content;
        int count = 0;
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
        Course** mycourse;
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
    vector <Course*> CourseList;
    public:
    void CreateNewCourse() {
        string courseName;
        cout << "ENTER THE COURSE NAME: ";
        cin >> courseName;
        Course* course =
            new Course(CourseList.size() + 1, courseName);
        cout << "\nA COURSE MUST HAVE AT LEAST ONE SUBJECT.\n";
        char subjectChoice;
        do {
            string subjectName;

            cout << "\nENTER SUBJECT NAME: ";
            cin >> subjectName;

            Subject* subject =
                new Subject(course->count + 1, subjectName);

            cout << "A SUBJECT MUST HAVE AT LEAST ONE TOPIC.\n";

            char topicChoice;

            do {
                string topicName;

                cout << "ENTER TOPIC NAME: ";
                cin >> topicName;

                subject->syllabus.topics.push_back(topicName);

                cout << "ADD ANOTHER TOPIC? (Y/N): ";
                cin >> topicChoice;

            } while (topicChoice == 'Y' ||
                     topicChoice == 'y');

            // Add subject to course
            course->content.push_back(subject);

            cout << "\nADD ANOTHER SUBJECT? (Y/N): ";
            cin >> subjectChoice;

        } while (subjectChoice == 'Y' ||
                 subjectChoice == 'y');

        // Add course to manager
        CourseList.push_back(course);

        cout << "\nCOURSE CREATED SUCCESSFULLY!\n";
    }

        void PrintCourseDetails(int id){;
            for(int i = 0; i < CourseList.size(); i++) {
                if(CourseList[i]->getId() == id) {

                    Course* course = CourseList[i];

                    cout << "|----------------------------------|" << endl;
                    cout << "| Course ID   | " << course->getId() << endl;
                    cout << "| Course Name | " << course->topic << endl;
                    cout << "|----------------------------------|" << endl;
                    cout << "| Subjects                         |" << endl;
                    cout << "|----------------------------------|" << endl;

        for(int j = 0; j < course->content.size(); j++) {
            cout << "| " << course->content[j]->GetName() << endl;
        }

        cout << "|----------------------------------|" << endl;
    }
}
        }
    };

int main(int argc, char const *argv[]){
   
   CourseManager cm;
   cm. CreateNewCourse();
   cm. CreateNewCourse();
   cm. CreateNewCourse();
   cm.PrintCourseDetails(1);
   cm.PrintCourseDetails(3);

    return 0;
}