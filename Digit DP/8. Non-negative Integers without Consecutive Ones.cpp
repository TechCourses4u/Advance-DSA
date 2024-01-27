// Problem 8 : No of integers 
// i) whose binary representations do not contain consecutive ones
// Constraints :
// 0 <= n <= 10^9

// 600. Non-negative Integers without Consecutive Ones
https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/submissions/1148190260/
/* Approach : Digit DP
Time : O(32 * 2 * 2 * 10) // dp states * time for each dp state
Space : O(32 * 2 * 2) // dp vector
*/

class Solution {
    // index, tight , prev
    int dp[32][2][2];

    int f(int index, bool tight, bool prev,  int &n) {
        // Base Case : index out of bound
        if(index == 32)
            return 1;

        // already calculated
        if(dp[index][tight][prev] != -1)
            return dp[index][tight][prev];

		int ans = 0;
		// calculate limit for current index
        int limit = tight ? (n >> (31 - index)) & 1 : 1;

        for(int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);
            if((d & prev) == 0)   // not consecutive ones
                ans += f(index + 1, newTight, d, n);
        }

        return dp[index][tight][prev] = ans;
    }
public:
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        // index, tight , prev, n
        return f(0, true, false, n);
    }
};
