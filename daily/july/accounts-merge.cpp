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
#include <set>

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> res;
        vector<set<string>> temp(n);
        vi father(n);
        REP(i, 0, n - 1)
            father[i] = i;

        function<int(int)> check = [&](int x) -> int {
            if (father[x] != x)
                father[x] = check(father[x]);
            return father[x];
        };

        auto merge = [&](int x, int y) -> void {
            father[check(x)] = check(y);
        };

        map<string, int> record;
        REP(i, 0, n - 1)
        {
            int len = accounts[i].size();
            REP(j, 1, len - 1)
            {
                auto &email = accounts[i][j];
                if (record.count(email))
                    merge(record[email], i);
                else
                    record[email] = i;
            }
        }

        REP(i, 0, n - 1)
        {
            int tar = check(i);
            temp[tar].insert(accounts[i].begin() + 1, accounts[i].end());
        }

        REP(i, 0, n - 1)
        {
            if (check(i) == i)
            {
                res.push_back({});
                res.back().push_back(accounts[i][0]);
                res.back().insert(res.back().end(), temp[i].begin(), temp[i].end());
            }
        }

        return res;
    }
};