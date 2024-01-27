// Problem 3 : No of integers with 
// i) Count of even digits equal to count of odd digits.
// ii) and divisible by k.
// Constraints :
// 0 < low <= high <= 10^9
// 0 < k <= 20

// 2827. Number of Beautiful Integers in the Range
// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/submissions/1148126304/

/* Approach : Digit DP
Time : O(10 * 2 * 6 * 6 * 20 * 2 * 10) // dp states * time for each dp state
Space : O(10 * 2 * 6 * 6 * 20 * 2) // dp vector
*/

class Solution {
private:
	// index, tight, oddCount, evenCount, remainder, validNum(for handling leading 0 case)
    int dp[10][2][6][6][20][2];

    int f(int index, bool tight, int oddCount, int evenCount, int remainder, bool validNum, int &k, string& s) {
        // Base cases : 1. index out of bound
		if (index >= s.size())
            return (oddCount == evenCount) and (remainder == 0);
		// 2. Pruning
		if ((oddCount > 5) || (evenCount > 5)) 
            return 0;
        
		// already calculated
        if (dp[index][tight][oddCount][evenCount][remainder][validNum] != -1)
            return dp[index][tight][oddCount][evenCount][remainder][validNum];
		
		int ans = 0;
		// calculate limit for current index 
        int limit = tight ? s[index] - '0' : 9;
		
		// loop from 0 to limit
        for (int d = 0; d <= limit; d++) {
			int newTight = tight & (d == limit);
            if (validNum == false and d == 0) 	// handle leading zeros case
                ans += f(index + 1, newTight, oddCount, evenCount, remainder, false, k, s);
            else if (i % 2 == 0)
                ans += f(index + 1, newTight, oddCount, evenCount + 1, (remainder * 10 + d) % k, true, k, s);
            else
                ans += f(index + 1, newTight, oddCount + 1, evenCount, (remainder * 10 + d) % k, true, k, s);
        }
        return dp[index][tight][oddCount][evenCount][remainder][validNum] = ans;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
		// find answer from 0 to low-1
		string l = to_string(low - 1);
        memset(dp, -1, sizeof(dp)); 
        long countNum1 = f(0, 1, 0, 0, 0, 0, k, l);
		
		// find answer for 0 to high
		string h = to_string(high);
        memset(dp, -1, sizeof(dp));
        long countNum2 = f(0, 1, 0, 0, 0, 0, k, h);
		
        return countNum2 - countNum1;
    }
};
