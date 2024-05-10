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
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // ==================================
        //        状态压缩 + 动态规划
        // ==================================
        int n = jobs.size();
        int m = 1 << n;
        
        vi sums(m);
        for (int i = 0; i < n; ++i)
        {
            int bit = 1 << i;
            for (int j = 0; j < bit; ++j)
                sums[j | bit] = sums[j] + jobs[i];
        }

        // 初始化，前0个工作者分配的结果
        vi dp(sums);
        for (int i = 1; i < k; ++i)
        {
            for (int j = m - 1; j > 0; --j)
            {
                for (int s = j - 1; s > 0; s = (s - 1) & j)
                    dp[j] = min(dp[j], max(dp[s ^ j], sums[s]));
            }
        }
        return dp.back();
    }
};