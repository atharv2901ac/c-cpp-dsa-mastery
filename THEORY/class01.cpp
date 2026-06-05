#include<stdio.h>
#include<stdlib.h>
class box{
    public:
    double length;
    double height;
    double width;
};
int main(int argc, char const *argv[])
{
    box* x1;
    x1->length=5;
    x1->height=7;
    x1->width= 10;
    
    box* x2;
    x2->length=10;
    x2->height=3; 
    x2->width= 14;

    double volume1 = x1->height*x1->length*x1->width;
    double volume2 = x2->height*x2->length*x2->width;

    double mass1 = 200;
    double mass2 = 230;

    double density1;(mass1/volume1);
    double density2=(mass2/volume2);
    printf("VOLUME OF BOX 1: %lf", volume1);
    printf("VOLUME OF BOX 2: %lf", volume2);
    printf("DENSITY OF BOX 1: %lf", density1);
    printf("DENSITY OF BOX 2: %lf", density2);
    return 0;
}
