#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void EnterDetails(vector <int>& Marks){
    Marks.resize(3);
    cout << "ENTER THE MARKS OF PHYSICS: ";
    cin >> Marks[0];
    cout << "ENTER THE MARKS OF MATHS: ";
    cin >> Marks[1];
    cout << "ENTER THE MARKS OF CHEMISTRY: ";
    cin >> Marks[2];

    ofstream File("samplemarks.bin", ios::out | ios::binary);
    if(File.is_open()){
        size_t bytesToPack = Marks.size()*sizeof(int);
        File.write(reinterpret_cast<const char*>(Marks.data()),bytesToPack);
        File.close();
    }
}
void ReadDetails(){
    vector<int> Marks(3);
    ifstream File("samplemarks.bin", ios::in | ios::binary);

    if (File.is_open()) {
        File.read(reinterpret_cast<char*>(Marks.data()), Marks.size() * sizeof(int));
        File.close();

        cout << "PHYSICS MARKS: " << Marks[0] << endl;
        cout << "MATHS MARKS: " << Marks[1] << endl;
        cout << "CHEMISTRY MARKS: " << Marks[2] << endl;
    } else {
        cout << "File could not be opened." << endl;
    }

}
int main(int argc, char const *argv[])
{
    vector <int> Marks;
    EnterDetails(Marks);
    ReadDetails();
    return 0;
}

