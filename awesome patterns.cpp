#include <iostream>

using namespace std;

void print_rectangle(int, int);

int main() {
  print_rectangle(5,5);
  
  return 0;
}

void print_rectangle(int rows, int columns){
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < columns; j++)
                cout << " * ";
        cout << endl;
    }
}


void print_hollow_rectangle(int rows, int columns){
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < columns; j++){
            if (i == 0 || i == rows-1)
                cout << " * ";
            else {
                if (j == 0 || j == columns-1)
                    cout << " * ";
                else 
                    cout << "   ";
            }
        }
            
        cout << endl;
    }
}
