// Problem 1 : https://www.geeksforgeeks.org/digit-dp-introduction/
// You are given two intergers a and b.
// Print sum of all the digits appearing in the integers between a and b
// Constraints : 1 <= a < b <= 10^18

#include "bits/stdc++.h"
using namespace std;
 
// dp array : index, tight, sum
long long dp[19][2][174];			// 18*9 + 1
 
// recursive function
long long f(int index, bool tight, int sum, string& s) {
	// base case : index out of bounds
	if (index == s.size())
		return sum;
	
	// already calculated
	if (dp[index][tight][sum] != -1)
		return dp[index][tight][sum];
	
	long long ans = 0;
	// calculate limit for current index
	int limit = tight ? s[index] - '0' : 9;
	
	// loop from 0 to limit
	for(int d = 0; d <= limit; d++){
		int newTight = tight & (d == limit);
		ans += f(index + 1, newTight, sum + d, s);
	}
	// memoize state
	return dp[index][tight][sum] = ans;
}
 
// Returns sum of digits in numbers from a to b.
int rangeDigitSum(int a, int b)
{	
	// compute result for low - 1
	string l = to_string(a - 1);		// convert to string
	memset(dp, -1, sizeof(dp));			// reset dp array
	long long countNum1 = f(0, true, 0, l);	// recursive call
	
	// compute result for high
	string h = to_string(b);			// convert to string
	memset(dp, -1, sizeof(dp));			// reset dp array
	long long countNum2 = f(0, true, 0, h);	// recursive call
	
	return (countNum2 - countNum1);
}
 
// driver function to call above function
int main() {
	long long a = 8, b = 15;
	cout << "range digit sum : " << rangeDigitSum(a, b) << endl;
	return 0;
}
