#include <iostream>
#include <string>

namespace colors {
    std::string HEADER = "\033[95m";
    std::string OKBLUE = "\033[94m";
    std::string OKGREEN = "\033[92m";
    std::string WARNING = "\033[93m";
    std::string FAIL = "\033[91m";
    std::string ENDC = "\033[0m";
    std::string BOLD = "\033[1m";
    std::string UNDERLINE = "\033[4m";
}


using namespace std;
using namespace colors;


void add_horizontal_rule();
void print_rectangle(int, int);
bool is_boundry(int,int,int);
void print_hollow_rectangle(int,int);
void print_inverted_half_pyramid(int);

int main() {
    cout << FAIL;
    print_rectangle(5,5);
    cout << OKBLUE;
    print_hollow_rectangle(5,5);
    cout << OKGREEN;
    print_inverted_half_pyramid(5);
    cout << ENDC;
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

void print_inverted_half_pyramid(int height) {
    for (int i = height; i >= 0; i--){
        for (size_t j = 0; j < i; j++)
            cout << " * ";
        cout << endl;
    }
}

