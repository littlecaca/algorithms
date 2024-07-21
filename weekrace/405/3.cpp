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
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vvi record(n, vi(2));
        int ans = 0;
        REP(i, 0, m - 1)
        {
            int xc = 0, yc = 0;
            REP(j, 0, n - 1)
            {
                if (grid[i][j] == 'X')
                    ++record[j][0];
                else if (grid[i][j] == 'Y')
                    ++record[j][1];
                xc += record[j][0];
                yc += record[j][1];
                if (xc == yc && xc > 0)
                    ++ans;
            }
        }
        return ans;
    }
};