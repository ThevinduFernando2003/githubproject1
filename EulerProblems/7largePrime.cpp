#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long num){
    if(num < 2) return false;

    for(int i = 2; i * i <= num; ++i){
        if(num % i == 0) return false;
    }
    return true;
}

int getPrime(long long n){
    long long count = 0, num = 1;
    while(count < n){
        ++num;
        if(isPrime(num)){
            ++count;
        }
    }
    return num;
}

int main(){
    long long number;
    number = getPrime(10001);
    cout << number << endl;
    return 0;
}