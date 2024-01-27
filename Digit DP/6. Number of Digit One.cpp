// Problem 6 : Count digit 1 occurrence in numbers up to n.
// Constraints :
// 0 <= n <= 10^9

// 233. Number of Digit One
// https://leetcode.com/problems/number-of-digit-one/submissions/1148181735/

/* Approach : Digit DP
Time : O(10 * 2 * 10 * 10) // dp states * time for each dp state
Space : O(10 * 2 * 10) // dp vector
*/

class Solution {
public:
    // index, tight, oneCount
    int dp[10][2][10];
    int f(int index, bool tight, int oneCount, string &s){
        // base case : index out of bound
        if(index == s.size()) 
            return oneCount;

        // already calculated
        if(dp[index][tight][oneCount] != -1)
            return dp[index][tight][oneCount];

        int ans = 0;
        // calculate limit for current index
        int limit = tight ? s[index] - '0' : 9;

        // loop from 0 to limit
        for(int d = 0; d <= limit; d++){
            int newTight = tight & (d == limit);
            ans += f(index + 1, newTight, oneCount + (d == 1), s);
        }
        return dp[index][tight][oneCount]= ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        // index, tight, oneCount, s
        return f(0, true, 0, s);
    }
};
