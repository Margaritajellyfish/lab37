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
   for (int hash = 0; hash < 97 && count < 100; ++hash) {
        if (hash_table.find(hash) != hash_table.end()) { 
            cout << "Hash Index: " << hash << " -> ";
            for (const string& str : hash_table[hash]) {
                cout << str << " ";
                count++;
                if (count >= 100) break; 
            }
            cout << endl;
        }
    }

    return 0;
}


/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
