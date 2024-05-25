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


		/**
		 * 将多重背包转换为0-1背包————超时
		 * 
		 * 
		*/
        vi C(n + 1);
		for (auto i : nums)
			++C[i];
		// Sum of nums does not exceed 2 * 10**4
		r = min(n, r);
		vi dp(r + 1);
		dp[0] = 1 + C[0];
		int sum = 0;

		REP(i, 1, r)
		{
			int c = C[i];
			if (c == 0) continue;
			sum = min(sum + i * c, r);

			_REP(j, sum, i)
			{
				REP(k, 1, c)
				{
					if (j - k * i >= 0)
						dp[j] = (dp[j] + dp[j - k * i]) % mod;
				}
			}
		}
		int ans = 0;
		REP(i, l, r)
			ans = (ans + dp[i]) % mod;
		return ans;
    }
};