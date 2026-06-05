#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    int rollno;
    char name[40];
};

Student** AddNewStudent(Student** list, int* count){
    Student* s = new Student();
    s->rollno = 100;
    strcpy(s->name,"ATHARV");
    if(list ==NULL){
        list =(Student**) malloc(1*sizeof(Student*));
    }
    else{
        realloc(list,(*count+1)*sizeof(Student*));
    }   
    list[*count] = s;
    *count = *count+1;
   return list;
}

int main(int argc, char const *argv[])
{
    
    Student** list = NULL;
    int count = 0;
    // allocate menory for a pointer
    list = AddNewStudent(list,&count);
    list = AddNewStudent(list,&count);

    printf("%d\n %d",list[0]->rollno,list[1]->rollno);

    return 0;
}