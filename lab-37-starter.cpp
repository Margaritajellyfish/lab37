#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;
void print_100_(map<int, list<string>>& hash_table) {
int count = 0;
    for (int hash = 0; hash < 997 && count < 100; ++hash) {
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
}   

int gen_hash_index(const string& input) {
    int hash_index = 0;
    for (char c : input) {
        hash_index += (int)c; 
    }
    return hash_index % 997; 
}
void sch_key(map<int, list<string>>& hash_table) {
    cout << "search code: ";
    string code;
    cin >> code;
    int hash = gen_hash_index(code);

    auto it = hash_table.find(hash);
    if (it == hash_table.end()) {
        cout << "Code not found." << endl;
        return;
    }
    for (auto& val : it->second) {
        if (val == code) {
            cout << code << " found in hash index " << hash << "." << endl;
            return;
        }
    }
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
    int choice;

    do{
        cout<< "1. print first 100 entries\n"
            << "2. search for a key\n"
            << "3. add a key\n"
            << "4. remove a key\n"
            << "5. modify a key\n"
            << "6. exit\n"
            << "choice: ";
        cin >> choice;
        switch (choice){
             case 1:
                print_100(hash_table);
                break;
            case 2:
                sch_key(hash_table);
                break;
            case 3:
                add_key(hash_table);
                break;
            case 4:
                remov_key(hash_table);
                break;
            case 5:
                mod_key(hash_table);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        }while (choice != 6);

        return 0;
    }


    