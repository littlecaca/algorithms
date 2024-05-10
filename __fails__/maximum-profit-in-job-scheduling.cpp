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

// ==========================================
//                  dp + 二分法
// ------------------------------------------
//           时间复杂度：O（n2）
//  
// ==========================================


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vi orderred(n);
        for (int i = 0; i < n; ++i)
            orderred[i] = i;
        sort(orderred.begin(), orderred.end(), [&](int a, int b) { return endTime[a] < endTime[b]; });
        vi dp(n);
        dp[0] = profit[orderred[0]];
        for (int i = 1; i < n; ++i)
        {
            // 二分法找到endTime > 当前startTime的job
            int left = 0, right = i - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (endTime[orderred[mid]] > startTime[orderred[i]])
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            int tar = right;
            int selected;
            if (tar < 0)
                selected = profit[orderred[i]];
            else
                selected = dp[tar] + profit[orderred[i]];
            
            dp[i] = max(dp[i - 1], selected);
        }
        return dp[n - 1];
    }
};
