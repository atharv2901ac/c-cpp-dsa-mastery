// do while used five chances game
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int guess;
    int attempts = 0;

    srand(time(0));

    int target = rand() % 100 + 1;

    printf("===== NUMBER GUESSING GAME =====\n");
    printf("You only have 5 chances \n");

    do{

        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if(guess > target){

            printf("Too High!\n");
        }

        else if(guess < target){

            printf("Too Low!\n");
        }

        else{

            printf("\nCORRECT GUESS \n");
            printf("Number was: %d\n", target);
            printf("Attempts Used: %d\n", attempts);

            return 0;
        }

    }while(attempts < 5);

    printf("\nGAME OVER \n");
    printf("Correct Number Was: %d\n", target);

    return 0;
}