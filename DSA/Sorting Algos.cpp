#include <iostream>

using namespace std;

void sort(char**, int);
bool compare(char*, char*);
bool compare(char*, char*, int&);
void swap(char*, char*);
void printArray(char**, int);


int main(){

    char** names = new char*[5];
    for (size_t i = 0; i < 5; i++)
    {
        names[i] = new char(50);
        cout << "Enter Name(" << i+1 << "): ";
        cin.getline(names[i],50);
    }
    cout << "UNSORTED" << endl;
    printArray(names, 5);
    sort(names,5);

    cout << "SORTED" << endl << endl;
    printArray(names, 5);

    // for (size_t i = 0; i < 5; i++)
    // {
    //     delete[] names[i];
    // }

    // delete[] names;

    delete (names);

return 0;

}

void printArray(char** wordList, int listSize){
    for (int i = 0;i < listSize;i++){
        if (wordList[i][0] == '\0')
            return;
        cout << wordList[i] << endl;
    }
}

void sort(char** wordList, int listSize){
    for (size_t i = 0; i < listSize; i++){ // iterate over item list
        for (size_t j = i; j < listSize - i - 1; j++){ // compares 
            if (compare(wordList[j], wordList[j+1])){
                swap(wordList[j], wordList[j+1]);
            }
        }
    }
}

/**
 * @brief 
 * 
 * @param str1 
 * @param str2 
 * @return true if str1 is is above or equal to str2 in descending order
 * @return false if str2 is greater than str2
 */
bool compare(char* str1, char* str2){
    int depth = 0;
    return compare(str1, str2, depth);

}

bool compare(char* str1, char* str2, int& depth){
    if (str1[depth] == '\0')
        return  true;
    if (str2[depth] == '\0')
        return false;
    if (str1[depth] < str2[depth] )
        return true;
    if (str1[depth] > str2[depth])
        return false;
    cout << str1 << endl;
    return compare(str1, str2, ++depth);
}


void swap(char* str1, char* str2){
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++){
        char temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
    }
}
