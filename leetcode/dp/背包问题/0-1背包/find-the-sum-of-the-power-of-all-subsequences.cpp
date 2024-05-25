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
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        constexpr int mod = 1e9 + 7;

        vector<ll> dp(k + 1);
        dp[0] = 1;
        for (int num : nums)
        {
            _REP(i, k, 0)
            {
                dp[i] = (dp[i] * 2) % mod;
                if (i - num >= 0)
                    dp[i] = (dp[i] + dp[i - num]) % mod;
            }
        }
        return dp.back();
    }
};