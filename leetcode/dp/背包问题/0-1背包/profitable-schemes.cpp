#include <unordered_set>
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
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        constexpr int mod = 1e9 + 7;

        vvi dp(n + 1, vi(minProfit + 1));
        REP(i, 0, n)
            dp[i][0] = 1;
        
        int N = group.size();
        REP(i, 0, N - 1)
        {
            int num = group[i], prof = profit[i];
            _REP(j, n, num)
                _REP(k, minProfit, 0)
                    dp[j][k] = (dp[j][k] + dp[j - num][max(k - prof, 0)]) % mod;
        }
        return dp.back().back();
    }
};
