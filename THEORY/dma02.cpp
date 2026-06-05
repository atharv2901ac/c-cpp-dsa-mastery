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

int main(int argc, char const *argv[])
{
     
    Student *list = NULL;
    int count = 0;
    char choice;
    Application(&list[count]);
    do
    {
        list =(Student*) realloc(list, (count + 1) * sizeof(Student));

        if (list == NULL)
        {
            printf("Memory Allocation Failed!");
            return 1;
        }

        

        count++;

        printf("Add another student? (y/n): ");
        scanf(" %c", &choice);

    } 
    while (choice == 'y' || choice == 'Y'){

    printf("\n----- RECORDS -----\n");

    for (int i = 0; i < count; i++)
    {
        Application(list);
    }
}
    free(list);

    return 0;
}

    
