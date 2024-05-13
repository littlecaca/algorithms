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
    int minimumSubstringsInPartition(string s) {
        #define INF ((int)1e8 + 8)
        int n = s.size();
        vvi count(n + 1, vi(26));
        for (int i = 1; i <= n; ++i)
        {
            count[i] = count[i - 1];
            ++count[i][s[i - 1] - 'a'];
        }
        vi dp(n + 1, INF);
        dp[0] = 0;
        
        auto check = [&](int a, int b) -> bool {
            auto &c1 = count[a], &c2 = count[b];
            int stand = -1;
            for (int i = 0; i < 26; ++i)
            {
                auto diff = c1[i] - c2[i];
                if (diff > 0)
                {
                    if (stand == -1)
                        stand = diff;
                    else if (stand != diff)
                        return false;
                }
            }
            return true;
        };

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (check(i, j))
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};