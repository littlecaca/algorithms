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
//        时间复杂度：平均o(n)，最坏O(n2)
// ==========================================


class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vi dp(nums.size(), 1);
        vi most_left(nums.size(), 1);
        ll ans = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            int j;
            for (j = i - 1; j >= 0; )
            {
                if (nums[i] > nums[j])
                    j -= most_left[j];
                else if (nums[i] == nums[j])
                {
                    dp[i] = dp[j] + 1;
                    break;
                }
                else break;
            }
            most_left[i] = i - j;
            ans += dp[i];
        }
        return ans;
    }
};