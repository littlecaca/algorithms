#include <map>
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
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int m = arr2.size();
        int n = arr1.size();

        /**
         * 动态规划
         * 令f[i][j]表示前i个元素调整j次的最后一个元素的最小值。
         */
        int k = min(m, n);
        vvi f(n + 1, vi(k + 1, INT_MAX));
        f[0][0] = -1;

        REP(i, 1, n)
        {
            int cur = arr1[i - 1];
            int z = min(i, k);
            bool done = false;

            REP(j, 0, z)
            {
                if (cur > f[i - 1][j]) f[i][j] = cur;
                if (j > 0 && f[i - 1][j - 1] != INT_MAX)
                {
                    int tar = f[i - 1][j - 1];
                    auto it = upper_bound(arr2.begin(), arr2.end(), tar);
                    if (it != arr2.begin() + m)
                        f[i][j] = min(f[i][j], *it);
                }
                if (f[i][j] != INT_MAX)
                {
                    done = true;
                    if (i == n) return j;
                }
            }
            if (!done) return -1;
        }

        return -1;
    }
};