#include <map>
#include <climits>
#include <functional>
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

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vpii> record;
        REP(i, 0, m - 1)
            REP(j, 0, n - 1)
                record[mat[i][j]].push_back({i, j});

        vi rows(m);
        vi cols(n);

        for (auto &node : record)
        {
            /**
             * 用一个数组保存相同值下一个状态，然后一次
             * 性更新
             */
            vi temp;
            for (auto &p : node.second)
                temp.push_back(max(rows[p.first], cols[p.second]) + 1);
            REP(i, 0, temp.size() - 1)
            {
                int x = node.second[i].first, y = node.second[i].second;

                rows[x] = max(rows[x], temp[i]);
                cols[y] = max(cols[y], temp[i]);
            }
        }

        return *max_element(rows.begin(), rows.end());
    }
};
