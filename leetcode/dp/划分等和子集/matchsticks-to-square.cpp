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
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int tar = sum / 4;
        
        // ============================
        //      解法一：0-1背包问题dp
        // ============================
        // 超内存，dp数组太大了O(k*n**3)
        // vvvi dp(tar + 1, vvi(tar + 1, vi(tar + 1)));
        // dp[0][0][0] = 1;
        // for (int i = 0; i < matchsticks.size(); ++i)
        // {
        //     for (int x = tar;  x >= 0; --x)
        //     {
        //         for (int y = tar; y >= 0; --y)
        //         {
        //             for (int z = tar; z >= 0; --z)
        //             {
        //                 if (x >= matchsticks[i])
        //                     dp[x][y][z] += dp[x - matchsticks[i]][y][z];
        //                 if (y >= matchsticks[i])
        //                     dp[x][y][z] += dp[x][y - matchsticks[i]][z];
        //                 if (z >= matchsticks[i])
        //                     dp[x][y][z] += dp[x][y][z - matchsticks[i]];
        //             }
        //         }
        //     }
        // }
        // return dp[tar][tar][tar];

        // ========================
        //      解法二：暴力回溯
        // ========================
        // 暴力回溯，不排序的容易超时O(4**k)
        // vi sides(4, tar);
        // sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        // function<bool(int)> backtracking = [&](int cur) -> bool {
        //     if (cur == matchsticks.size()) return true;
        //     for (int i = 0; i < 4; ++i)
        //     {
        //         int len = matchsticks[cur];
        //         if (len <= sides[i])
        //         {
        //             sides[i] -= len;
        //             if (backtracking(cur + 1)) return true;
        //             sides[i] += len;
        //         }
        //     }
        //     return false;
        
        // };
        // return backtracking(0);

        // ==================================
        //      解法三：状态压缩 + 动态规划
        // ==================================
        // 巧妙地只考虑当前一条边，并用一个整数表示选择的火柴的状态。
        // 有序的填充每一条边，最终满足条件的一定是所有边都填充进去后，
        // 当前的边的剩余为填充长度为0。
        int n = matchsticks.size();
        vi dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < dp.size(); ++s)
        {
            // 通过控制最后一个填充元素，模拟了不同的填充顺序
            for (int i = 0; i < n; ++i)
            {
                if ((s & (1 << i)) == 0) continue;
                int s1 = s & ~(1 << i);
                if (dp[s1] >= 0 && matchsticks[i] <= tar - dp[s1])
                {
                    dp[s] = (dp[s1] + matchsticks[i]) % tar;
                    break;
                }
            }
        }
        return dp.back() == 0;
        
    }
};