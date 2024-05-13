#include <array>
#include <unordered_set>
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
#include <map>

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
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        #define MOD (int)(1e9 + 7)
        
        ll ans = 0;
        ll sum = accumulate(arr.begin(), arr.end(), 0);
        ll cur = 0;
        bool flag = false;
        for (int i = 0; i < arr.size(); ++i)
        {
            cur += arr[i];
            ans = max(ans, cur);
            if (cur < 0) cur = 0;
            if (i == arr.size() - 1 && k > 1 && !flag && cur > 0)
            {
                i = -1;
                flag = true;
            }
        }

        // 当sum > 0时，两个重复的arr连接起来的数组的最大子数组一定经过跨越中间，
        // 因此，ans就等于k个arr连接后前后连个arr的贡献的最大值之和。
        if (sum > 0)
        {
            int temp = max(0, k - 2);
            ans = (temp * sum + ans) % MOD;
        }
        return ans % MOD;
    }
};
