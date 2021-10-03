#include <iostream>
#include <string>

namespace colors {
    std::string HEADER = "\033[95m";
    std::string OKBLUE = "\033[94m";
    std::string OKGREEN = "\033[92m";
    std::string WARNING = "\033[93m";
    std::string RED_FG = "\033[91m";
    std::string RED_BG = "\033[101m";
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
void print_half_right_pyramid(int);
void print_number_half_left_pyramid(int);
void print_floyd_triangle(int);
void print_butterfly(int);
void print_binary_half_left_pyramid(int);
void print_palindromic_number_pyramid(int);
void print_diamond(int);
void print_hollow_diamond(int);

int main() {
    // // cout << FAIL;
    // print_rectangle(5,5);
    // // cout << OKBLUE;
    // print_hollow_rectangle(5,5);
    // // cout << OKGREEN;
    // print_inverted_half_pyramid(5);
    // // cout << WARNING;
    // print_half_right_pyramid(5);
    // // cout << ENDC;
    // print_number_half_left_pyramid(5);
    // print_floyd_triangle(5);
    // print_butterfly(5);
    // print_binary_half_left_pyramid(5);
    // print_palindromic_number_pyramid(9);

    // print_diamond(5);
    print_hollow_diamond(5);
    return 0;
}

void add_horizontal_rule(){
    cout << endl;
    cout << colors::RED_FG << "< ---------------------------------------- >" << colors::ENDC << endl;
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
    // outer loop iterates over the rows
    for (int i = height; i > 0; i--){
        for (size_t j = 0; j < i; j++)
            cout << RED_FG << " * " << ENDC;
        for (size_t k = 0; k < (height - i); k++)
            cout << RED_BG << "   " << ENDC;
        cout << endl;
    }
}

void print_half_right_pyramid(int height){
    for (int i = height; i > 0; i--)
    {
        int spaces = i - 1;
        int stars = height - spaces;
        for (size_t j = 0; j < spaces; j++)
            cout << RED_BG << "   " << ENDC;
        for (size_t k = 0; k < stars; k++)
            cout << RED_FG << " * " << ENDC;
        cout << endl;
    }
    
}

void print_number_half_left_pyramid(int height){
    for (size_t i = 1; i <= height; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << " " << i << " ";
        }
        cout << endl;
        
    }
    
}

void print_floyd_triangle(int height){
    int count = 1;
    for (size_t i = 1; i <= height; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << " " << count++ << " ";
        }
        cout << endl;
        
    }
    
}

void print_butterfly(int size) {
    int width = size*2;
    for (int i = 0; i <= size; i++)
    {
        int spaces = (size - i)*2;

        for (size_t j = 0; j < i; j++)
            cout << " * ";
        for (size_t j = 0; j < spaces; j++)
            cout << "   ";
        for (size_t j = 0; j < i; j++)
            cout << " * ";
        cout << endl;
    }
    for (int i = 0; i < size; i++)
    {
        int stars = size - i;
        int spaces = width - (stars*2);
        for (size_t j = 0; j < stars; j++)
            cout << " * ";
        for (size_t j = 0; j < spaces; j++)
            cout << "   ";
        for (size_t j = 0; j < stars; j++)
            cout << " * ";
        cout << endl;
    }
    
}

void print_binary_half_left_pyramid(int height){
    for (size_t i = 1; i <= height; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << " " << (i+j)%2 << " ";
        }
        cout << endl;
        
    }
    
}

void print_palindromic_number_pyramid(int height) {

    for (size_t i = 1; i <= height; i++)
    {
        int spaces = height - i;
        for (size_t j = 0; j < spaces; j++)
        {
            cout << "   ";
        }
        for (size_t j = i; j > 0; j--)
        {
            cout << " " << j << " ";
        }
        for (size_t j = 2; j <= i; j++)
        {
            cout << " " << j << " ";
        }
        cout << endl;
    }
    
}

void print_diamond(int rows) {
    int spaces;

    for (size_t i = 1; i <= rows; i++)
    {
        spaces = rows - i;
        for (size_t j = 0; j < spaces; j++)
            cout << " ";
        for (size_t j = 0; j < 2*i-1; j++)
            cout << "*";
        cout << endl;
    }
    
    for (size_t i = rows; i > 0; i--)
    {
        spaces = rows - i;
        for (size_t j = 0; j < spaces; j++)
            cout << " ";
        for (size_t j = 0; j < 2*i-1; j++)
            cout << "*";
        cout << endl;
    }
    
}

void print_hollow_diamond(int rows) {
        int spaces;

    for (size_t i = 0; i < rows; i++)
    {
        spaces = rows - i;
        for (size_t j = 0; j < spaces; j++)
            cout << " ";
        cout << "*";
        int blanks = 2*i-1;
        for (int j = 0; j < blanks; j++)
        {
            cout << " ";
        }
        cout << "*";
        
        cout << endl;
    }
    for (size_t i = rows; i > 0; i--)
    {
        spaces = rows - i;
        for (size_t j = 0; j < spaces; j++)
            cout << " ";
        cout << "*";
        for (int j = 0; j < 2*i-1; j++)
        {
            cout << " ";
        }
        cout << "*";
        
        cout << endl;
    }
    
}
