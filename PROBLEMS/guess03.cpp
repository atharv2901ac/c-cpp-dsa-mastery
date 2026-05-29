//do while used, no limits
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int guess;
    int attempts = 0;

    srand(time(0));

    int target = rand() % 100 + 1;

    printf("===== NUMBER GUESSING GAME =====\n");
    printf("Guess a number between 1 and 100\n");

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

            printf("\nCORRECT GUESS:\n");
            printf("Number was: %d\n", target);
            printf("Attempts: %d\n", attempts);
        }

    }while(guess != target);

    return 0;
}