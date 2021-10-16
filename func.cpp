#include <iostream>
#include <cmath>

using namespace std;

int factorial(int);
double factorial(double);
int* search_primes(int, int);
bool is_prime(int);

int main() {
    // cout << factorial(4e+0);
    // cout << TEST.get_name();
    // int* primes = search_primes(1,100);
    // cout << "TOTAL PRIMES FOUND: " << *primes << endl;
    // for (size_t i = 0; i < *primes; i++)
    //     cout << primes[i];
    
    // delete[] primes;
    // cin;
    return 0;
}

double factorial(double n){
    return n == 1 ? 1 : factorial(n-1)*n;
}

int factorial(int n){
    return n == 1 ? 1 : factorial(n-1)*n;
}

int* search_primes(int a, int b){
    if (b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    
    int max_size = 10;
    int* primes = new int[max_size+1];
    int* size = primes++;
    for (size_t i = a; i < b; i++)
    {
        if (is_prime(i)){
            if (*size == max_size){
                max_size*= 2;
                int* temp = new int[max_size+1];
                memcpy(temp,primes, (max_size/2) * sizeof(int));
                delete[] primes;
                primes = temp; 
                delete[] temp;
            }
            *primes = i;
            primes++;
            *size++;
        }

    }

    return primes;
    
}


bool is_prime(int n){
    for (size_t i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    
    return true;
}

