#include <unordered_set>
#include <climits>
#include <functional>
#include <queue>
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
    int minimumDistance(vector<vector<int>>& points) {
        /**
         * 曼哈顿距离与切比雪夫距离的转换
         * manhattan: (x1, y1), (x2, y2) => |x1 - x2| + |y1 - y2| 
         *                               => max{|(x1 + y1) - (x2 + y2)|, |(x1 - y1) - (x2 - y2)|}
         * chebyshev: (x1, y1), (x2, y2) => max{|x1 - x2|, |y1 - y2|}
         * 
         * 所以chebyshev(((x1 + y1, x1 - y1), (x2 + y2, x2 - y2))) == manhattan((x1, y1), (x2, y2))
         * 
         */
        int n = points.size();
        vector<pii> sx, sy;
        REP(i, 0, n - 1)
        {  
            auto x = points[i][0],
                 y = points[i][1];

            sx.emplace_back(x - y, i);
            sy.emplace_back(x + y, i);
        }

        sort(sx.begin(), sx.end());
        sort(sy.begin(), sy.end());

        int maxVal1 = sx.back().first - sx[0].first;
        int maxVal2 = sy.back().first - sy[0].first;

        int res = INT_MAX;
        int i, j;
        if (maxVal1 >= maxVal2)
        {
            i = sx.front().second;
            j = sx.back().second; 
        }
        else
        {
            i = sy.front().second;
            j = sy.back().second; 
        }
        res = min(res, max(remove(sx, i), remove(sy, i)));
        res = min(res, max(remove(sx, j), remove(sy, j)));

        return res;
    }

    int remove(vector<pii> &arr, int i)
    {
        int n = arr.size();
        if (i == arr.front().second)
            return arr.back().first - arr[1].first;
        else if (i == arr.back().second)
            return arr[n - 2].first - arr.front().first;
        else
            return arr.back().first - arr.front().first;
    }
};