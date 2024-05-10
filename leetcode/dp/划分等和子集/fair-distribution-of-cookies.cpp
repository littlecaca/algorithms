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
        // ===========================
        

    }
};