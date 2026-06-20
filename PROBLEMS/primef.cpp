#include <iostream>
using namespace std;

void factorise(int,int);

int main(int argc, char const *argv[])
{
    int num;
    cout << "ENTER A NUMBER: ";
    cin >> num;
    printf("PRIME FACTORS OF THE FOLLOWING NUMBERS ARE: ");
    factorise(num,2);
    return 0;
}

void factorise(int n, int i){
    if(i <= n){
        if(n % i == 0){
             i ;
            n = n/i;
        }
        else{
            i++;
            factorise(n,i);
        }
    }
}