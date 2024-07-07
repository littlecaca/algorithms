#include <numeric>
#include <stack>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>

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

class Solution
{
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        // auto check = [&](const vi &lhs, const vi &rhs) -> bool
        // {
        //     REP(i, 0, n - 1)
        //     {
        //         if (lhs[i] && rhs[i])
        //             return false;
        //     }
        //     return true;
        // };
        // if (m == 1 && accumulate(grid[0].begin(), grid[0].end(), 0) == 0)
        //     return {0};
        // REP(i, 0, m - 1)
        // {
        //     REP(j, i + 1, m - 1)
        //     {
        //         if (check(grid[i], grid[j]))
        //             return {i, j};
        //     }
        // }
        // return {};

        unordered_map<int, int> mp;
        REP(i, 0, m - 1)
        {
            int st = 0;
            for (auto j : grid[i])
                st = (st | j) << 1;
            mp[st] = i;
        }

        if (mp.count(0))
            return {mp[0]};

        for (auto [x, i] : mp)
        {
            for (auto [y, j] : mp)
            {
                if (!(x & y))
                    return {min(i, j), max(i, j)};
            }
        }
        return {};
    }
};