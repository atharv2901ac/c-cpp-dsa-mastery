#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    char name[50];
    int phy;
    int maths;
    int chem;
    float total;
    float percnt;
};

void Application(Student *s){
    printf("ENTER THE FOLLOWING DETAILS :)\n\n");
    printf("ENTER YOUR ROLL NO. : ");
    scanf("%d", &s->rollno);
    printf("ENTER MARKS OF PHYSICS : ");
    scanf("%d", &s->phy);
    printf("ENTER MARKS OF MATHS : ");
    scanf("%d", &s->maths);
    printf("ENTER MARKS OF CHEMISTRY : ");
    scanf("%d", &s->chem);
    s->total=s->phy+s->maths+s->chem;
    printf("YOUR TOTAL SCORE : %f\n", s->total);
    s->percnt=(s->total/300)*100;
    printf("PERCENTAGE ACHIEVED: %f\n\n", s->percnt);
}
Student** addEntry(Student** StudentList, int* count){
    
    Student* s = new Student();
    Application(s);
    if(StudentList == NULL){
        StudentList = (Student**) malloc(1*sizeof(Student*));
    }
    else{
        StudentList = (Student**) realloc(StudentList,(*count+1)*sizeof(Student*));
    }
    StudentList[*count] = s;
    *count = *count + 1;
    return StudentList;
}

int main(int argc, char const *argv[])
{
    Student** StudentList = NULL;
    int count = 0;
    StudentList = addEntry(StudentList,&count);
    StudentList = addEntry(StudentList,&count);
    StudentList = addEntry(StudentList,&count);
    return 0;
}
