// Problem 2 : No of integers with sum between given range
// Constraints :
// 1 <= num1 <= num2 <= 10^22
// 1 <= min_sum <= max_sum <= 400

// 2719. Count of Integers
// https://leetcode.com/problems/count-of-integers/submissions/1148008569/

/* Approach : Digit DP
Time : O(23 * 2 * 401 * 10) // dp states * time for each dp state
                            // num2.size * 2 * maxSum * 10
Space : O(23 * 2 * 401) // dp vector
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    long dp[23][2][401];

    long f(int index, bool tight, int sum, int &min_sum, int &max_sum, string &s) {
        if (index == s.size())
            return sum >= min_sum and sum <= max_sum;

        if (dp[index][tight][sum] != -1)
            return dp[index][tight][sum];

        long ans = 0;
		// calculate limit for current index
		int limit = tight ? s[index] - '0' : 9;

		// loop from 0 to limit
		for(int d = 0; d <= limit; d++){
			int newTight = tight & (d == limit);
			ans += (f(index + 1, newTight, sum + d, min_sum, max_sum, s) % mod);
		}
        return dp[index][tight][sum] = ans;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
		// compute result for low
		memset(dp, -1, sizeof(dp));			// reset dp array
		long countNum1 = f(0, true, 0, min_sum, max_sum, num1);	// recursive call
		
		// compute result for high
		memset(dp, -1, sizeof(dp));			// reset dp array
		long countNum2 = f(0, true, 0, min_sum, max_sum, num2);	// recursive call
		
		// we need from 1 to low - 1, so check result for low seperately
        int sum = 0;
        for (auto d : num1)
            sum += (d - '0');

        if (sum >= min_sum and sum <= max_sum)
            countNum1--;

        return (((countNum2 - countNum1) % mod) + mod) % mod;
    }
};
