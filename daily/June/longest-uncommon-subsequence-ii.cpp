#include <unordered_set>
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
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string &lhs, const string &rhs) -> bool {
            return lhs.size() > rhs.size();
        });

        int n = strs.size();
        vector<bool> valid(n, true);

        unordered_map<string, int> record;
        for (auto &s : strs)
            ++record[s];

        REP(i, 0, n - 1)
        {
            if (!valid[i]) continue;
            if (record[strs[i]] == 1) return strs[i].size();
            REP(j, i + 1, n - 1)
            {
                if (isCommon(strs[j], strs[i]))
                    valid[j] = false;
            }
        }
        return -1;
    }

    bool isCommon(const string &s1, const string &s2) const
    {
        int left = 0, right = 0;
        int m = s1.size(), n = s2.size();
        while (left < m && right < n)
        {
            if (s1[left] == s2[right])
            {
                ++left; ++right;
            }
            else
             ++right;
        }
        if (left == m) return true;
        return false;
    }
};