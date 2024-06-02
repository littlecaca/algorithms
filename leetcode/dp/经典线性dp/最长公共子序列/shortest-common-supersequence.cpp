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
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vvi dp(n1 + 1, vi(n2 + 1));
        REP(i, 0, n1)
            dp[i][0] = i;
        REP(j, 0, n2)
            dp[0][j] = j;

        REP(i, 1, n1)
        {
            char c1 = str1[i - 1];
            REP(j, 1, n2)
            {
                char c2 = str2[j - 1];
                if (c1 == c2)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else    
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

        string ans(dp.back().back(), 0);
        for (int i = n1, j = n2, cur = ans.size() - 1; cur >= 0; --cur)
        {
            int value = dp[i][j];
            if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1])
            {
                ans[cur] = str2[j - 1];
                --i; --j;
            }
            else if (i > 0 && value == dp[i - 1][j] + 1)
            {
                ans[cur] = str1[i - 1];
                --i;
            }
            else 
            {
                ans[cur] = str2[j - 1];
                --j;
            }
        }
        return ans;
    }
};