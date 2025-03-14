#include <string>
#include <iostream>
using namespace std;

int main() {
	// Complete the program
    string a, b;
    cin >> a ;
    cin >> b ;
    
    int n = a.size();
    int m = b.size();
    
    string c = a+b;
    string d = a.substr(1,n);
    string e = b.substr(1,m);
    cout << n << " " << m << endl;
    cout << c <<endl;
    cout << b[0] << d << " " << a[0] << e << endl;
    
  
    return 0;
}