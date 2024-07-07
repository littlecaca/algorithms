#include <climits>
#include <string>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>

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

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vi dp(n + 1, INT_MAX);
        dp[0] = 0;
        REP(i, 1, n)
        {
            unordered_map<int, int> record;
            int cnt = 0;
            _REP(j, i, 1)
            {
                int t = ++record[nums[j - 1]];
                if (t == 2)
                    cnt += 2;
                else if (t > 2)
                    cnt += 1;

                dp[i] = min(dp[i], dp[j - 1] + cnt + k);
            }
        }
        return dp.back();
    }
};