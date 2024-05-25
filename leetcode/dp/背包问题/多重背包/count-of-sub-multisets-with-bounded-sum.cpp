#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <numeric>
#include <iostream>
#include <climits>
#include <forward_list>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

# define REP(i,a,b) for(int i = a; i <= b; ++i)
# define _REP(i,a,b) for(int i = a; i >= b; --i)
# define DEBUG(num) cout << "debug: " << num << endl;

template <typename T>
bool chmin(T &a, const T &b)
{
	if (a <= b) return false;
	a = b;
	return true;
}


class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
		constexpr int mod = 1e9 + 7;
		int n = accumulate(nums.begin(), nums.end(), 0);

        vi C(n + 1);
		for (auto i : nums)
			++C[i];
		// Sum of nums does not exceed 2 * 10**4
		r = min(n, r);
		vi dp(r + 1);
		dp[0] = 1 + C[0];
		int sum = 0;

		/**
		 * 朴素dp
		*/
		// REP(i, 1, n)
		// {
		// 	int c = C[i];
		// 	if (c == 0) continue;
		// 	sum = min(sum + i * c, r);
		// 	vi new_dp = dp;

		// 	REP(j, i, sum)
		// 	{
		// 		dp[j] = (dp[j] + dp[j - i]) % mod;
		// 		if (i * (c + 1) <= j)
		// 			dp[j] = (dp[j] - new_dp[j - i * (c + 1)] + mod) % mod;
		// 	}	
		// }

		/**
		 * 同余前缀和
		*/
		REP(i, 1, n)
		{
			int c = C[i];
			if (c == 0) continue;
			sum = min(sum + i * c, r);
			
			REP(j, i, sum)
				dp[j] = (dp[j] + dp[j - i]) % mod;
			int t = (c + 1) * i;
			_REP(j, sum, t)
				dp[j] = (dp[j] - dp[j - t] + mod) % mod;
		}
		int ans = 0;
		REP(i, l, r)
			ans = (ans + dp[i]) % mod;
		return ans;
    }
};