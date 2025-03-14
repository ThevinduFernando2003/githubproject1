//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


//  Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findSingle(vector<int> &arr) {
        // code here
        int result = 0; 
        for(int i = 0; i < arr.size(); i++){
            result ^= arr[i];
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.findSingle(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends