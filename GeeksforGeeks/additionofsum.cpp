//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Driver Code Ends
class Solution {
  public:
    int sumOfDigits(int n) {
        // code here
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

//Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfDigits(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends