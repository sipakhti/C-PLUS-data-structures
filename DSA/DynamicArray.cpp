#include <iostream>

using namespace std;

class DynamicArray
{
private:
    int* array = nullptr;
    unsigned int size{};
    unsigned int capacity;
    int max{INT_MIN}, min{INT_MAX};

    bool is_full(){
        return size >= capacity;
    }

    void expand_array(){
        int* temp = new int(capacity*2);
        array_cpy(temp);
        delete[] array;
        array = temp;
        delete temp;
        capacity*=2;

    }

    void array_cpy(int* destination){
        for (size_t i = 0; i < size; i++)
            destination[i] = array[i];
        
    }


public:
    DynamicArray(unsigned int cap){
        array = new int[size];
        capacity = cap;
    }

    void push(int number){
        if (is_full())
            expand_array();

        array[size] = number;
        size++;
    }

    int pop(){
        size--;
        int pop = array[size];
        return pop;
    }

    int first_index(int number){
        for (size_t i = 0; i < size; i++)
            if (array[i] == number)
                return i;
        return -1;
        
    }

    int last_index(int number){
        for (size_t i = size; i >= 0; i--)
            if (array[i] == number)
                return i;
        return -1;
        
        
    }

    int* to_array(){
        int* temp = new int[size];
        array_cpy(temp);
        return temp;
    }

    void print_array(){
        cout << "-----------------------------" << endl;
        cout << "CAPACITY: " << capacity << endl;
        cout << "SIZE: " << size << endl;
        for (size_t i = 0; i < size; i++)
            cout << "at index " << i << " :- " << array[i] << endl;
        cout << "CAPACITY: " << capacity << endl;
        cout << "SIZE: " << size << endl;
        cout << "-----------------------------" << endl;
    }


    // int* all_indices(int number){
    //     DynamicArray* indices = new DynamicArray(10);
    //     for (size_t i = 0; i < size; i++)
    //         if (array[i] == number)
    //             indices.push(number);
        

    //     return indices.to_array();

    // }



    //DynamicArray(int* &source_array, int length);

};




int main(){



    DynamicArray array(10);

    array.push(10);
    array.push(15);
    array.push(78);
    array.push(99);
    array.push(1156);
    array.push(54646445);
    cout << "POP: " << array.pop() << endl;
    array.push(99);
    array.push(-98); 
    array.push(5465); 
    array.push(3513); 
    array.push(47);
    array.push(99); 
    array.push(898); 
    array.push(4598); 
    array.print_array();
    cout << array.first_index(99) << endl;
    cout << array.last_index(99) << endl;
    return 0;

}