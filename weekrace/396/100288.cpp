#include <unordered_map>
#include <cstdlib>
#include <set>
#include <string>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;

#define MOD (int)(1e9 + 7)
template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        ll sum = 0;
        int mx = 0, mn = INT_MAX;
        for (auto n : nums)
        {
            sum += n;
            mx = max(mx, n);
            mn = min(mn, n);
        }
        ll need = mx * nums.size() - sum;
        if (cost2 >= cost1 * 2)
            return need * cost1 % MOD;
        if (cost2 >= cost1)
        {
            if (mx - mn > need / 2)
                return ((need - mx + mn) * cost2 % MOD + (2 * mx - 2 * mn - need) * cost1 % MOD) % MOD;
            else
                return (need / 2 * cost2 % MOD + need % 2 * cost1 % MOD) % MOD;
        }
        ll ans = LLONG_MAX;
        for (int tar = mx; tar <= 2 * mx; ++tar)
        {
            need = tar * nums.size() - sum;
            if (tar - mn > need / 2)
                ans = min(ans, ((need - tar + mn) * cost2 + (2 * tar - 2 * mn - need) * cost1));
            else
                ans = min(ans, need / 2 * cost2 + need % 2 * cost1);
        }
        return ans % MOD;
    }
};