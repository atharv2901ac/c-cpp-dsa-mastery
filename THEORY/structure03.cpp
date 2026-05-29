#include<stdio.h>
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

void Application(Student* s){
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
void ApplicationList(Student* list[], int* count){
    if(*count<5){
        Student* s= new Student();
        Application(s);
        list[*count]=s;
        *count = *count+1;
    }
    else{
        printf("CANNOT INSERT MORE DETAILS<<<<<<<LIST IS FULL\n");
    
    }

}
void highestRank(Student* list[], int count){

    int top = 0;

    for(int i = 1; i < count; i++){

        if(list[i]->percnt > list[top]->percnt){

            top = i;
        }
    }

    printf("\n===== TOPPER =====\n");
    printf("ROLL NO: %d\n", list[top]->rollno);
    printf("PERCENTAGE: %.2f\n", list[top]->percnt);
}
void lowestRank(Student* list[], int count){

    int low = 0;

    for(int i = 1; i < count; i++){

        if(list[i]->percnt < list[low]->percnt){

            low = i;
        }
    }

    printf("\n===== LOWEST RANK =====\n");
    printf("ROLL NO: %d\n", list[low]->rollno);
    printf("PERCENTAGE: %.2f\n", list[low]->percnt);

}
void swap (Student* a, Student* b){
    Student temp = *a;
    *a = *b;
    *b = temp;
}
void rank(Student* list[], int count){

    for(int i = 0; i < count - 1; i++){

        for(int j = 0; j < count - i - 1; j++){

            if(list[j]->percnt < list[j+1]->percnt){

                swap(list[j], list[j+1]);
            }
        }
    }

    printf("\n===== RANKINGS =====\n");

    for(int i = 0; i < count; i++){

        printf("%d. Roll No: %d | Percentage: %.2f\n",
        i+1,
        list[i]->rollno,
        list[i]->percnt);
    }
}
void subjecttopphy(Student* list[], int count)
{
    int top = 0;

    for(int i = 1; i < count; i++){

        if(list[i]->phy > list[top]->phy){

            top = i;
        }
    }

    printf("\n===== TOPPER OF PHYSICS =====\n");
    printf("ROLL NO: %d\n", list[top]->rollno);
    printf("MARKS ACQUIRED IN PHYSICS: %d\n", list[top]->phy);
}
void subjecttopchem(Student* list[], int count)
{
    int top = 0;

    for(int i = 1; i < count; i++){

        if(list[i]->chem > list[top]->chem){

            top = i;
        }
    }

    printf("\n===== TOPPER OF CHEMISTRY =====\n");
    printf("ROLL NO: %d\n", list[top]->rollno);
    printf("MARKS ACQUIRED IN CHEMISTRY: %d\n", list[top]->chem);
}
void subjecttopmath(Student* list[], int count)
{
    int top = 0;

    for(int i = 1; i < count; i++){

        if(list[i]->maths > list[top]->maths){

            top = i;
        }
    }

    printf("\n===== TOPPER OF MATHS =====\n");
    printf("ROLL NO: %d\n", list[top]->rollno);
    printf("MARKS ACQUIRED IN MATHS: %d\n", list[top]->maths);
}
void average(Student* list[], int count){
    int k;
    for(int i = 0; i<count; i++){
        k=k+list[i]->percnt;
    }
    printf("\n===== AVERAGE SCORE =====\n");
    printf("SCORE: %d\n", k/count);
}
int main(){
    Student* list[5] ;
    int count = 0;
    ApplicationList(list,&count);
    ApplicationList(list,&count);
    ApplicationList(list,&count);
    ApplicationList(list,&count);
    ApplicationList(list,&count);

    
    
    rank(list,count);
    lowestRank(list,count);
    highestRank(list,count);
    subjecttopphy(list,count);
    subjecttopchem(list,count);
    subjecttopmath(list,count);
    average(list,count);
}