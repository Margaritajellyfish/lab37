#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;


int gen_hash_index(const string& input) {
    int hash_index = 0;
    for (char c : input) {
        hash_index += (int)c; 
    }
    return hash_index % 97; 
}
int main() {
    ifstream fin;
    fin.open("lab-37-data.txt");
    string line;
    
    map<int, list<string>> hash_table;
    if(!fin.is_open()){cout << "fail to open file.";}

    while(getline(fin, line)){
        int hash = gen_hash_index(line);
        hash_table[hash].push_back(line); 
    }
    fin.close();
    
    int count = 0;
    do{for (const auto& [hash, strings] : hash_table) {

        cout << "Hash Index: " << hash << " -> ";
        for (const string& str : strings) {
            cout << str << " ";
            count++;
        }
        cout << endl;
        
    }}while (count <100);

    return 0;
}


/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
