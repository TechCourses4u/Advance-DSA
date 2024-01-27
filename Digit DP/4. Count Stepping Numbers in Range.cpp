// Problem 5 : No of integers such that
// i) adjacent digits have an absolute difference of exactly 1
// Constraints :
// 1 <= int(low) <= int(high) < 10^100
// low and high don't have any leading zeros.

// 2801. Count Stepping Numbers in Range
// https://leetcode.com/problems/count-stepping-numbers-in-range/submissions/1148166469/

/* Approach : Digit DP
Time : O(101 * 2 * 10 * 2 * 10) // dp states * time for each dp state
Space : O(101 * 2 * 10 * 2) 	// dp vector
*/

typedef long long ll;
class Solution {
public:
    ll mod = 1e9 + 7;
    // index, tight, prev, validNum
    ll dp[101][2][10][2];

    ll f(int index, bool tight, int prev, bool validNum, string& s) {
        // base case : index out of bound
        if(index == s.size()){
            if(validNum) return 1;
            return 0;
        }

        // already calculated
        if(dp[index][tight][prev][validNum] != -1)
            return dp[index][tight][prev][validNum];
        
        ll ans = 0;
        // calculate limit for current index
        int limit = tight ? s[index] - '0' : 9;

        // loop from 0 to limit
        for (int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);
            if (validNum == false and d == 0) 	// handle leading zeros case
                ans += (f(index + 1, newTight, prev, false, s) % mod);
            else if (validNum == false and d > 0) 	// first digit > 0
                ans += (f(index + 1, newTight, d, true, s) % mod);
            else if (abs(d - prev) == 1)            // 2nd or further digit > 0
                ans += (f(index + 1, newTight, d, true, s) % mod);
        }
        return dp[index][tight][prev][validNum] = ans;
    }

    int countSteppingNumbers(string low, string high) {
		// find answer for low
        memset(dp, -1, sizeof(dp));
        ll countNum1 = f(0, true, 0, 0, low);
		
		// we need from 1 to low - 1, so check result for low seperately     
        int i = 1;
        while(i < low.size()){
            if(abs((low[i] - '0') - (low[i - 1] - '0')) != 1)
                break;
            i++;
        }
        if(i == low.size())
            countNum1--;
			
        // find answer from 1 to high
        memset(dp, -1, sizeof(dp));
        ll countNum2 = f(0, true, 0, 0, high);
     
        return (((countNum2 - countNum1) % mod) + mod) % mod;
    }
};
