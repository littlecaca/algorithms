#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}


class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        /**
         * 关键在于了解，最优堆叠方法是让最长边为高。
         * 
         * 假设两个立方体的三维长从低到高排序分别为，w1, l1, h1; w2, l2, h2;
         * 则第二个立方体能够叠到第一个立方体上的必要条件是w1 >= w2, l1 >= l2, h1 >= h2;
         * 由此可得，如果第一个立方体不选最长边作为高，叠在其上的立方体还是要满足上面的条件，
         * 不会有更多的可以叠放的立方体。
        */
        int ans = 0;

        for (auto &cube : cuboids)
            sort(cube.begin(), cube.end());

        sort(cuboids.begin(), cuboids.end(), [](const vi &c1, const vi &c2) -> bool {
            return  c1[0] + c1[1] + c1[2] < c2[0] + c2[1] + c2[2];
        });

        auto compare = [](const vi &c1, const vi &c2) -> bool {
            return c1[0] >= c2[0] && c1[1] >= c2[1] && c1[2] >= c2[2];
        };  

        int n = cuboids.size();

        vi dp(n);

        REP(i, 0 , n - 1)
        {
            int old = 0;
            REP(j, 0, i - 1)
            {
                if (compare(cuboids[i], cuboids[j]))
                    old = max(old, dp[j]);
            }
            dp[i] =  old + cuboids[i][2];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
