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
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int cur = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            ans = max(ans, prices[i] - cur);
            cur = min(cur, prices[i]);
        }
        return ans;
    }
};