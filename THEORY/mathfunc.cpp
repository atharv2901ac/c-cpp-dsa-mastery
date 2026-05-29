#include<stdio.h>
#include"common01.h"
int main(int argc, char const *argv[])
{
    float num;

    printf("ENTER A NUMBER: ");
    scanf("%f", &num);

    printf("SQUARE ROOT: %.1f", sqrt(num));
    return 0;
}
