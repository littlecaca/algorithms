#include <numeric>
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
#define INF 0x3f3f3f3f

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
    int minimumMoves(vector<vector<int>>& grid) {
        vvi record;
        vvi zero;
        REP(i, 0, 2)
        {
            REP(j, 0, 2)
            {
                if (grid[i][j] > 1)
                {
                    record.push_back({i, j, grid[i][j] - 1});
                }
                else if (grid[i][j] == 0)
                    zero.push_back({i, j});
            }
        }
        int res = INT_MAX;
        auto dist = [](const vi &a, const vi &b) -> int {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };

        function<void(int, int)> backTracking = [&](int i, int move) -> void {
            if (i == zero.size())
            {
                res = min(res, move);
                return;
            }

            for (auto &cell : record)
            {
                if (cell[2] == 0) continue;
                --cell[2];
                backTracking(i + 1, move + dist(cell, zero[i]));
                ++cell[2];
            }
        };
        backTracking(0, 0);
        return res;
    }
};