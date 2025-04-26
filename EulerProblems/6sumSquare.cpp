#include <bits/stdc++.h>
using namespace std;

int main(){

    long long sumSquares = 0;
    long long totalSum = 0;

    for(int i = 1; i <= 100; i++){
        sumSquares += i * i;
    }

    for(int i =1; i <= 100; i++){
        totalSum += i;
    }

    long long difference = totalSum * totalSum - sumSquares;

    cout << difference << endl;
    return 0;
}