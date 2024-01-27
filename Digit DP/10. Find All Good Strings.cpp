// Problem 10 : No of strings 
// i) that does not contain evil as a substring
// Constraints :
// s1.length == s2.length == n
// 1 <= n <= 500
// 1 <= evil.length <= 50
// All strings consist of lowercase English letters.

// 1397. Find All Good Strings
// https://leetcode.com/problems/find-all-good-strings/submissions/1148204095/

// KMP algo : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

/* Approach : Digit DP
Time : O(501 * 2 * 51 * alphabetSize * evil.size()) // dp states * time for each dp state
Space : O(501 * 2 * 51) // dp vector
*/

typedef long long ll;
class Solution {
public:
    ll mod = 1e9 + 7;
    // index, tight, chars matching with Evil prefix
    ll dp[501][2][51];     
    int lps[51];

    ll f(int index, bool tight, int matchCount, string& s, string& evil, int lps[]){
		// Base case : 1. Evil string found
        if(matchCount == evil.size())
            return 0;
			
		// 2. index out of bound
        if(index == s.size())
                return 1;
				
        // already calculated
        if(dp[index][tight][matchCount] != -1)
            return dp[index][tight][matchCount];

		ll ans = 0;
        // calculate limit for current index 
        char limit = tight ? s[index] : 'z';    // lowercase alphabets

        for(char c = 'a'; c <= limit; c++){
            int newTight = tight & (c == limit);

            // Find newMatchCount using KMP search algo
            int newMatchCount = matchCount;
            while((newMatchCount != 0) && (evil[newMatchCount] != c))
                newMatchCount = lps[newMatchCount - 1];
            if(evil[newMatchCount] == c)
                newMatchCount++;

            // recurse with newTight and newMatchCount
            ans += (f(index + 1, newTight, newMatchCount, s, evil, lps) % mod);
        }

        return dp[index][tight][matchCount] = ans;
    }

    // compute lps[] for given pattern pat[0..size-1]
    void computeLPSArray(string& pat, int size, int lps[]) {
        // length of the previous longest prefix suffix
        int len = 0;
        lps[0] = 0; // lps[0] is always 0
    
        // calculate lps[i] for i = 1 to size-1
        int i = 1;
        while (i < size) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {    // (pat[i] != pat[len])
                if (len != 0)
                    len = lps[len - 1];
                else {      // if (len == 0)
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        // create lps array for evil string using KMP algo
        // lps - longest proper prefix which is also a suffix
        memset(lps, 0, sizeof(lps));
        computeLPSArray(evil, evil.size(), lps);

		// find answer from 1 to low
        memset(dp, -1LL, sizeof(dp));
        ll countNum1 = f(0, true, 0, s1, evil, lps); 	// index, tight, match count
		
        // we need from 1 to low - 1, so check result for low seperately 
        // search if evil is present in low i.e. s1
        // we used stl, can also use kmp search algorithm  
        if(s1.find(evil) == string::npos)    // evil not present in s1
            countNum1--;
	
        // find answer from 1 to high
        memset(dp, -1, sizeof(dp));
        ll countNum2 = f(0, true, 0, s2, evil, lps);  

        return (((countNum2 - countNum1) % mod) + mod) % mod;
    }
};
