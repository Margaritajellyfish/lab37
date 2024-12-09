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
    return hash_index % 997; 
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


    


/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
