// Problem 7 : No of integers 
// i) ending with a given suffix
// ii) and each digit less than given limit
// Constraints :
// 1 <= start <= finish <= 10^15
// 1 <= limit <= 9
// 1 <= s.length <= floor(log10(finish)) + 1
// s only consists of numeric digits which are at most limit.
// s does not have leading zeros.

// 2999. Count the Number of Powerful Integers
// https://leetcode.com/problems/count-the-number-of-powerful-integers/submissions/1148154926/

/* Approach : Digit DP
Time : O(16 * 2 * 10) // dp states * time for each dp state
Space : O(16 * 2) // dp vector
*/

typedef long long ll;
class Solution {
public:
	// index, tight
    ll dp[16][2]; 
	
    ll f(int index, bool tight, int& maxAllowed, string &suffix, string &s){
        // Base case : index out of bound
        if(index == s.size()) 
			return 1;

        // already calculated
        if(dp[index][tight] != -1)
            return dp[index][tight];
        
		ll ans = 0;
        // calculate limit for current index 
        int limit = tight ? s[index] - '0' : 9;
        limit = min(limit, maxAllowed);

        int suffixIndex = s.size() - suffix.size();
        // two cases :
        // 1. Index in suffix range - special handling
        if(index >= suffixIndex) {
            // tight 0 ==> we can fill remaining places with suffix values and create matching suffix
            if(tight == false)      
                return dp[index][tight] = 1;

            // number suffix < required suffix -> can't create matching suffix
            if(s[index] < suffix[index - suffixIndex]) 
                return dp[index][tight] = 0;
            
            // number suffix == required suffix -> can fill this index, check for others
            if(s[index] == suffix[index - suffixIndex]) 
                return dp[index][tight] = f(index + 1, true, maxAllowed, suffix, s);
            
            // number suffix > required suffix -> can create matching suffix
            if(s[index] > suffix[index - suffixIndex])
                return dp[index][tight] = 1;
        }
        
        // 2. Index not in suffix range - normal digit dp
        for(int d = 0; d <= limit; d++) {
            int newTight = tight & (d == s[index] - '0');
            ans += f(index + 1, newTight, maxAllowed, suffix, s);
        }

        return dp[index][tight] = ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int maxAllowed, string suffix) {
        // find answer from 1 to low-1
        ll countNum1 = 0;
        string l = to_string(start - 1);
        if(l.size() >= suffix.size()) {
            memset(dp, -1, sizeof(dp));
            countNum1 = f(0, true, maxAllowed, suffix, l);
        }

		// find answer from 1 to high
        string h = to_string(finish);
        memset(dp, -1LL, sizeof(dp));
        ll countNum2 = f(0, true, maxAllowed, suffix, h); 
        
        return countNum2 - countNum1;
    }
};
