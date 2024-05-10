#include <bitset>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        vi dp(n + 1, 1);
        dp[0] = 0;
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp.back();
    }
};