#include <climits>
#include <stack>
#include <queue>
#include <vector>

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

// ==========================================
//             一维动态规划
// ------------------------------------------
//           时间复杂度：最坏O(n2)
//    就本题而言，表现比单调栈算法要好，可能
//  是因为单调栈需要频繁申请和读写内存。
// ==========================================
//                单调栈
// ------------------------------------------
//           时间复杂度: O(n) (V)
//         (单调栈经典题——熟练掌握)
//            失败原因: 没做到
// ------------------------------------------
//             打卡：x
// ==========================================


class Solution {
public:
    // 一维动态规划
    // long long numberOfSubarrays(vector<int>& nums) {
    //     vi dp(nums.size(), 1);
    //     vi most_left(nums.size(), 1);
    //     ll ans = 1;

    //     for (int i = 1; i < nums.size(); ++i)
    //     {
    //         int j;
    //         for (j = i - 1; j >= 0; )
    //         {
    //             if (nums[i] > nums[j])
    //                 j -= most_left[j];
    //             else if (nums[i] == nums[j])
    //             {
    //                 dp[i] = dp[j] + 1;
    //                 break;
    //             }
    //             else break;
    //         }
    //         most_left[i] = i - j;
    //         ans += dp[i];
    //     }
    //     return ans;
    // }

    long long numberOfSubarrays(vector<int>& nums) {
        ll ans = nums.size();
        // 每个元素{a, b}中，a代表nums[i],b代表在栈中连续出现的次数
        stack<pii> sta;
        // 放入哨位结点，简化判断逻辑
        sta.push({INT_MAX, 0});

        for (int n : nums)
        {
            while (n > sta.top().first)
                sta.pop();
            if (n == sta.top().first)
            {
                ans += sta.top().second;
                ++sta.top().second;
            }
            else
                sta.push({n, 1});
        }

        return ans;
    }
};