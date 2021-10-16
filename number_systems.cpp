#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <stdexcept>
#include <typeinfo>
#include <exception>
// #include <number_systems.h>

using namespace std;

string dec_to_bin(int);
int bin_to_dec(string);
bool is_prime(int);
int number_reverser(int);
int optimized_number_reverser(int);
bool is_armstrong_number(int);

int main() {
    // char exit = 'n';
    // do
    // {
    // int number;
    // cin >> number;
    // cout << number << " : " << dec_to_bin(number) << endl;
    // cout << "press 'n' to end: ";
    // cin >> exit;
    // } while (exit != 'n');
    
    // string bin;
    // cout << "ENTER BINARY NUMBER: ";
    // cin >> bin;
    // try
    // {
    //     int test = bin_to_dec(bin);
    //     cout << bin << " : " << test;
    // }
    // catch(const overflow_error& e)
    // {
    //     cerr << e.what() << '\n';
    // }

    cout << number_reverser(1203) << endl;
    cout << optimized_number_reverser(43221) << endl;
    cout << 12345%1000 << "  " << 12345%1000/100;
    // string meh = is_armstrong_number(153) ? "armstrong" : "meh";
    // cout << meh;

    return 0;
}

string dec_to_bin(int number){
    int mod;
    stack<int> stack;
    while(number != 0){
        stack.push(number%2);
        number/=2;
    }
    string str;
    while(!stack.empty()){
        str.append(to_string(stack.top()));
        stack.pop();
    }
    return str;

}

int bin_to_dec(string bin){
    if (bin.size() > 31 )
        throw new overflow_error("your input bit size(" + to_string(bin.size()) + ") is greater than 31. unsigned integer max usable bit size is 31!");
    int power = bin.size()-1;
    int number = 0;
    for (size_t i = 0; i < bin.size(); i++, power--)
        number = bin[i] == '1' ? number + pow(2,power) : number;
    

    return number;
    
}

bool is_prime(int n){
    for (size_t i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    
    return true;
}

// it doesnt resolve edge cases properly in which the number ends with one or more than one zero
int number_reverser(int number){
    int base_10_power{0};
    int mirror_num{0};
    // loop to determine the length of the number
    for (int modulator = 10; modulator < INT_MAX; modulator*=10, base_10_power++)
        if (number%modulator == number)
            break;

    // this loop actually reverses the number
    // it uses the information from the previous loop
    // it iterates over the number from left to right
    // as it iterates over the number, it pops one digit at a time
    for (int i = base_10_power; i >= 0; i--)
    {
        // this is the postion of the digit in terms of power of base 10
        int original_digit_pos = pow(10,i);
        // the left most digit of the number
        int left_most_digit = number/original_digit_pos;
        // this is exact opposite of original_digit_pos
        int mirrored_digit_pos = pow(10,base_10_power - i);
        // this is where the left most digit is multiplied with the correct factor to place it in a mirrored postion
        mirror_num += left_most_digit * mirrored_digit_pos;
        // this is where the left most digit is removed otherwise it will become the left most digit of the subsequent slicing
        number -= left_most_digit * original_digit_pos;
    }
    return mirror_num;
}

int optimized_number_reverser(int number){

    int reverse{0};
    int last_digit{0};
    while(number > 0){
        last_digit = number%10;
        reverse = reverse*10 + last_digit;
        number/=10;
    }

    return  reverse;
}

bool is_armstrong_number(int number){

    int temp_num{number};
    int armstrong{0};
    while(temp_num > 0){
        armstrong += pow(temp_num%10,3);
        temp_num/=10;
    }
    return armstrong == number;
}