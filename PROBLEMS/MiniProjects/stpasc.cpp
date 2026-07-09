#include <iostream>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoices(char choice);
void chooseWinner(char player, char computer);

int main(int argc, char const *argv[])
{
    char player;
    char computer;

    player = getUserChoice();
    cout << "YOU CHOSE: ";
    showChoices(player);
    
    return 0;
}

char getUserChoice(){
    char player;
    cout << "ROCK PAPER SCISSORS GAME.......!!!!!!" << endl;
    cout << "*************************************" << endl;
    do{
    cout << "CHOOSE ONE OF THE FOLLOWING:" << endl;
    cout << "'r' IS FOR ROCK" << endl;
    cout << "'p' IS FOR PAPER" << endl;
    cout << "'s' IS FOR SCISSORS" << endl;
    cin >> player;
    }
    while(player != 'r' && player != 's' && player != 'p');

    return 0;
}
char getComputerChoice(){

} 
void showChoices(char choice){

    if( choice == 'r'){
        cout << "ROCK\n";
    }
    else if( choice == 'p'){
        cout << "PAPER\n";
    }
    else if( choice == 's'){
        cout << "SCISSOR\n";
    }
    else{
        cout << "SORRY.... INVALID CHOICE ";
    }
    
}
void chooseWinner(char player, char computer){

}
