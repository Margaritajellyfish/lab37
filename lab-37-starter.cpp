#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int sum_ascii(const string& input);
int main() {
    ifstream fin;
    fin.open("lab-37-data.txt");
    long long sum = 0;
    string line;
    if(!fin.eof()){cout << "fail to open file.";}
    while(getline(fin, line)){
        sum += sum_ascii(line);
    }
    fin.close();
    
    cout << "The grand total of ASCII values is: " << sum;

    return 0;
}
int sum_ascii(const string& input){
    int sum = 0;
    for (char c : input) {
        sum += (int)c;
    }
    return sum;

}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
