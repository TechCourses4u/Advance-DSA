// Problem 9 : No of integers 
// i) with atleast one repeated digit
// Constraints :
// 0 <= n <= 10^9

// 1012. Numbers With Repeated Digits
// https://leetcode.com/problems/numbers-with-repeated-digits/submissions/1148194023/

/* Approach : Digit DP
Time : O(10 * 2 * 2 * 1024 * 10) // dp states * time for each dp state
Space : O(10 * 2 * 2 * 1024) // dp vector
*/

class Solution {
public:
    // index, tight, is repeated, bitmask to check repeated
    // 10 different digits (0 - 9) ==> max possible bitmask = 1111111111 = 1023
    int dp[10][2][2][1024];     

    int f(int index, bool tight, bool repeat, int bitmask, string& s){
        // base cases : index out of bound
        if(index == s.size()){
            if(repeat && bitmask)   // digit repeated and number is not zero
                return 1;
            return 0;
        }

        // already calculated
        if(dp[index][tight][repeat][bitmask] != -1)
            return dp[index][tight][repeat][bitmask];

		int ans = 0;
        // calculate limit for current index
        int limit = tight ? s[index] - '0' : 9;
        
        for(int d = 0; d <= limit; d++){
            int newTight = tight & (d == limit);
            if((bitmask == 0) && (d == 0))        // handle leading zeros case
                ans += f(index + 1, false, repeat, bitmask, s); 
            else if(bitmask & (1 << d))     // this digit is repeated
                ans += f(index + 1, newTight, true, bitmask, s);
            else                        // not repeated -> update bitmask
                ans += f(index+1, newTight, repeat, bitmask | (1 << d), s);
        }
        return dp[index][tight][repeat][bitmask] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return f(0, true, false, 0, s);
    }
};
