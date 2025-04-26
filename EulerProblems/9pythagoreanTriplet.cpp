#include <iostream> 
using namespace std;

int main(){

    int limit = 1000;

    for(int a = 1; a < limit; a++){
        for(int b = a+ 1; b < limit - a; b++){
            int c = limit - a- b;
            if(a*a +b*b == c*c){
                cout << a << " " << b << " " << c << endl;
                cout << a * b * c << endl;
                return 0;
            }
        }
    }
    return 0;
}