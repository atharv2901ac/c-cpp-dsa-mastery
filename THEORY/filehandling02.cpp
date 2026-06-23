#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    string line;
    ifstream file("sample.txt",ios::in);

    if(file.is_open()){
        while(getline(file,line)){
            cout << line << endl;
        }
        file.close();
    }
    else{
        cout << "THERE WAS AN ERROR IN OPENING THE FILE :( ";
    }
    return 0;
}