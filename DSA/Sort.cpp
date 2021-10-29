#include <iostream>

using namespace std;

// class Sort
// {
// private:
//     /* data */
//     void selection_pass_asec(int* numbers, int length, int pass){
//     int temp;
//         for (size_t i = 1 + pass; i < length; i++){
//             if (numbers[pass] > numbers[i]){
//                 temp = numbers[i];
//                 numbers[i] = numbers[pass];
//                 numbers[pass] = temp;
//             }
//         }
//     }

//     void selection_pass_desc(int* numbers, int length, int pass){
//         int temp;
//             for (size_t i = 1 + pass; i < length; i++){
//                 if (numbers[pass] < numbers[i]){
//                     temp = numbers[i];
//                     numbers[i] = numbers[pass];
//                     numbers[pass] = temp;
//                 }
//             }
//     }

    
// public:
//     Sort(/* args */);

//     void selection_sort(int* numbers, int length, bool asec=true){
//     int pass{};
//     while (pass < length)
//     {
//         if (asec)
//             this->selection_pass_asec(numbers,length, pass);
//         else 
//             this->selection_pass_desc(numbers, length, pass);
        
        
//         pass++;
//     }
//     }
// };

template <typename T>
class Sort
{
private:
    T* array= nullptr;
    int length{};

    void selection_pass_asec(int pass){
        int temp;
            for (size_t i = 1 + pass; i < length; i++){
                if (this->array[pass] > this->array[i]){
                    temp = this->array[i];
                    this->array[i] = this->array[pass];
                    this->array[pass] = temp;
                }
            }
    }

    void selection_pass_desc(int pass){
        int temp;
            for (size_t i = 1 + pass; i < length; i++){
                if (this->array[pass] < this->array[i]){
                    temp = this->array[i];
                    this->array[i] = this->array[pass];
                    this->array[pass] = temp;
                }
            }
    }


    
public:
    Sort(T* array, int length){
        this->array = array;
        this->length = length;
    };

    void selection_sort(bool asec=true){
        if (asec)
            for (size_t pass = 0; pass < this->length; pass++)
                this->selection_pass_asec(pass);
        else
            for (size_t pass = 0; pass < this->length; pass++)
                this->selection_pass_desc(pass);
        
        
    };

    T* get_array(){
        return this->array;
    }

};

void print_array(int*, int);
void print_array(char*, int);



int main(){
char* numbers = new char[10]{'\0'};
    cin.getline(numbers, 10);

Sort<char> sort(numbers, 10);
print_array(sort.get_array(), 10);
sort.selection_sort();
print_array(sort.get_array(), 10);
sort.selection_sort(false);
print_array(sort.get_array(), 10);


delete[] numbers;
return 0;

}

void print_array(char* str, int meh){
    for (size_t i = 0; str[i] != '\0'; i++)
        cout << str[i];
    cout << endl;
    
}


void print_array(int* numbers, int length){
    cout << "[ ";
    for (size_t i = 0; i < length; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << "]" << endl;
    
}
