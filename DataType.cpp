#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    for (size_t i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    
    cout << "MEH";
    return 0;
}