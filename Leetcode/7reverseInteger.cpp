#include <bits/stdc++.h>

class Solution {
    public:
        int reverse(int x) {
            long long rev = 0;
            while(x != 0){
                int digit = x%10;
                
                // Check for overflow before multiplying or adding
                if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
                if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;
                rev = rev * 10 + digit;
                x /= 10;
            }
            return (int)rev;
        }

        int main(){
            int x;
            cin >> x;
            int rev = reverse(x);
            cout << rev << endl;
            if(x>4) cout << "x";
            
            return 0;
        }
    };