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
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        constexpr int mod = 1e9 + 7;
        vi dp(target + 1);
        dp[0] = 1;
        for (auto &type : types)
        {
            int count = type[0], mark = type[1];
            _REP(i, target, 1)
            {
                REP(j, 1, count)
                {
                    if (i >= j * mark)
                        dp[i] = (dp[i] + dp[i - j * mark]) % mod;
                    else break;
                }
            }
        }
        return dp.back();
    }
};
