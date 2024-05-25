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
    string largestNumber(vector<int>& cost, int target) {
        /**
         * 动态规划
        */

        // vector<string> dp(target + 1, "_");
        // auto compare = [](const string &s1, const string &s2) -> bool
        // {
        //     if (s1.back() == '_') return true;
        //     if (s2.back() == '_') return false;
        //     if (s1.size() != s2.size())
        //         return s1.size() < s2.size();
        //     return s1 < s2;  
        // };

        // dp[0] = "";
        
        // REP(i, 1, target)
        // {
        //     REP(j, 0, 8)
        //     {
        //         if (i - cost[j] >= 0)
        //             dp[i] = max(dp[i], string(1, '1' + j) + dp[i - cost[j]], compare);
        //     }
        // }

        // return dp.back().back() != '_' ? dp.back() : "0";


        /**
         * 转化成完全背包问题
        */
        vi dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int c : cost)
            REP(i, c, target)
                dp[i] = max(dp[i], dp[i - c] + 1);

        if (dp.back() < 0) return "0";
        string ans;
        // 利用dp查找转移来源
        for (int i = 8, j = target; i >= 0; --i)
        {
            for (int c = cost[i]; j >= c && dp[j] == dp[j - c] + 1; j -= c)
                ans += '1' + i;
        }
        return ans;
    
    }
};