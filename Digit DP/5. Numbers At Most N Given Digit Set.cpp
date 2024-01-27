// Problem 5 : No of integers from 1 to n with 
// i) digits from given array any no of times
// Constraints :
// 1 <= n <= 10^9
// All the values in digits are unique.
// digits is sorted in non-decreasing order.

// 902. Numbers At Most N Given Digit Set
// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/submissions/1148175369/

/* Approach : Digit DP
Time : O(10 * 2 * 2 * 10) // dp states * time for each dp state
Space : O(10 * 2 * 2) // dp vector
*/

class Solution {
public:
    // index, tight, validNum
    int dp[10][2][2];
    int f(int index, bool tight, bool validNum, vector<string>& digits, string &s) {
        // Base Case : Outside boundary
        if(index == s.size()){
            if(validNum) return 1;
            return 0;
        }

        // already calculated
        if(dp[index][tight][validNum] != -1)
            return dp[index][tight][validNum];

		int ans = 0;
		// calculate limit for current index
        int limit = tight ? s[index] - '0' : 9;
        
        if (validNum == false) 	// adding leading zeros 
            ans += f(index + 1, false, false, digits, s);
        
        // loop for digits array
        for(auto it : digits){
            int d = stoi(it);	// string to integer
            int newTight = tight & (d == limit);
            if(d > limit) // number > s 
                break;
            ans += f(index + 1, newTight, true, digits, s);  
        }
        return dp[index][tight][validNum] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        // index, tight , validNum, digits, s
        return f(0, true, false, digits, s);
    }
};
