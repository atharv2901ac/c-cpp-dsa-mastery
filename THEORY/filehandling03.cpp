#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    string line;
    fstream file("sample.txt",ios::app);

    if(file.is_open()){
        file << "HELLO, I AM USING C++\n";
        file << "THIS IS THE APPLICATION OF FILE HANDLING\n";
        
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