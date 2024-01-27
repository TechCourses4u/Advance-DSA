/* Common code template to solve all digit dp problems */

class Solution {
public:
	// dp array declaration : index, tight, problem specific variables
    int dp[index][tight][xyz];     
	
	// recursive function
    int f(int index, bool tight, problem specific variables){
        // base cases : 1. index out of bound
		if(index == maxIndex)
            return something;
				
		// other problem specific base cases

        // dp state already calculated check
        if(dp[index][tight][xyz] != -1)
            return dp[index][tight][xyz];

		// ans variable declaration
		int ans = 0;
		
        // calculate limit for current index
		// eg: 34567 -> for index 2 (i.e. 5)
		// if tight is 1 -> 5 else 9
        int limit = tight ? s[index] : 9;
		
		// loop from 0 to limit
		for(int d = 0; d <= limit; d++){
			// calculate new Tight value as below
			// if tight is 1 and d == limit ==> newTight = 1
			// else newTight = 0
            int newTight = tight & (d == limit);
			
			// problem specific preprocessing if required
			
			// recurse for next index based on problem specific conditions
			if(some condition is true)
                ans += f(index + 1, newTight, xyz); 
            else if(some other condition is true)     
                ans += f(index + 1, newTight, xyz);
            else
                ans += f(index+1, newTight, xyz);
        }

		// memoize dp state
        return dp[index][tight][xyz] = ans;
    }

    int someProblem(int low, int high, problem specific variables) {
		// problem specific preprocessing if required
		
        // find result for low-1
		string l = to_string(low - 1);
		memset(dp, -1, sizeof(dp));
		// start from 0th index, pass tight as true, pass problem specific variables
		int countNum1 = f(0, true, l, xyz);
		
		// Repeat above steps for finding result for high
		string h = to_string(high);
		memset(dp, -1, sizeof(dp));
		int countNum2 = f(0, true, h, xyz);
		
		// ans will be result for 0 to high - result for 0 to low-1 
		// if result is calculated for low - 1, then
		return (countNum2 - countNum1);
		
		// Note 1 :
		// if result is calculated for 0 to low, then
		// first check for low seperately and then return result
        if(low satisfies condition)
            countNum1--;
        return (countNum2 - countNum1);
		
		// Note 2 : if for large values, ans needs to be return as mod
		return (((countNum2 - countNum1) % mod) + mod) % mod;
    }
};
