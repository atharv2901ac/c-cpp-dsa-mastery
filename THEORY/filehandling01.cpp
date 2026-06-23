#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    fstream file("sample.txt",ios::out);

    if(file.is_open()){
        file << "HELLO, I AM USING C++\n";
        file << "THIS IS FILE HANDLING\n";

        file.close();
    }
    else{
        cout << "THERE WAS AN ERROR IN OPENING THE FILE :( ";
    }
    return 0;
}
