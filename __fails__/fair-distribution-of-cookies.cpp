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
    int distributeCookies(vector<int>& cookies, int k) {
        // ==================
        //      暴力回溯
        // ==================
        // sort(cookies.begin(), cookies.end());
        // int sum = accumulate(cookies.begin(), cookies.end(), 0);
        // int tar = (sum + k - 1) / k;
        // int ans = INT_MAX;
        // vi counts(k);
        // function<void(int, int)> backTracking = [&](int cur, int child) -> void {
        //     if (cur == cookies.size())
        //     {
        //         ans = min(ans, *max_element(counts.begin(), counts.end()));
        //         return;
        //     }
        //     for (int i = 0; i < counts.size(); ++i)
        //     {
        //         if (counts[i] < tar)
        //         {
        //             counts[i] += cookies[cur];
        //             backTracking(cur + 1, i);
        //             counts[i] -= cookies[cur];
        //         }
        //         else break;
        //     }
        // };
        // backTracking(0, 0);
        // return ans;


        // ===========================
        //      状态压缩+动态规划
        //      O(C(n, i))
        // ===========================
        // 定义 dp[i][j] 表示前 i 个孩子分配的饼干集合为 j 时，
        // 前 i 个孩子的不公平程度的最小值。
        int m = 1 << cookies.size();

        // 先预先算好每个集合元素值之和
        vi sum(m);
        for (int i = 0; i < cookies.size(); ++i)
        {
            // 这样算，学废了吗？
            int bit = 1 << i;
            for (int j = 0; j < bit; ++j)
                sum[bit | j] = sum[j] + cookies[i];
        }

        // 然后递推
        vi dp(sum);

        for (int i = 1; i < k; ++i)
        {
            for (int j = m - 1; j > 0; --j)
            {
                // 这样遍历子集，学废了吗？
                for (int s = j; s > 0; s = (s - 1) & j)
                    dp[j] = min(dp[j], max(dp[s ^ j], sum[s]));
            }
        }
        return dp.back();
    }
};