#include <iostream>
#include <string>

using namespace std;

namespace colors {
    string HEADER = "\033[95m";
    string OKBLUE = "\033[94m";
    string OKGREEN = "\033[92m";
    string WARNING = "\033[93m";
    string FAIL = "\033[91m";
    string ENDC = "\033[0m";
    string BOLD = "\033[1m";
    string UNDERLINE = "\033[4m";
}

void print_rectangle(int, int);
bool is_boundry(int,int,int);
void print_hollow_rectangle(int,int);
void add_horizontal_rule();

int main() {
    cout << colors::WARNING;
    print_rectangle(5,5);
    add_horizontal_rule();
    cout << colors::OKBLUE;
    print_hollow_rectangle(5,5);
    
    cout << colors::ENDC;
    return 0;
}

void add_horizontal_rule(){
    cout << endl;
    cout << colors::FAIL << "< ---------------------------------------- >" << colors::ENDC << endl;
    cout << endl;
}

void print_rectangle(int rows, int columns){
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < columns; j++)
                cout << " * ";
        cout << endl;
    }
}

bool is_boundry(int val, int upper_bound, int lower_bound) {
    return val == lower_bound || val == --upper_bound;
}

void print_hollow_rectangle(int rows, int columns){
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < columns; j++){
            if (is_boundry(i,rows, 0))
                cout << " * ";
            else {
                if (is_boundry(j, columns, 0))
                    cout << " * ";
                else 
                    cout << "   ";
            }
        }
            
        cout << endl;
    }
}
