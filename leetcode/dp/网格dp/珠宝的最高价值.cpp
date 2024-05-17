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
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size(), n = frame[0].size();
        vi dp(n + 1);
        for (int i = 0; i < m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[j] = max(dp[j - 1], dp[j]) + frame[i][j - 1];
        return dp.back();
    }
};