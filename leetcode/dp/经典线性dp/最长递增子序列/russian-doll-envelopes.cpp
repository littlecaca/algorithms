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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vi &e1, const vi &e2) -> bool {
                return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        int ans = 0;
        vi temp;
        vi C(100001);

        for (auto &e : envelopes)
        {
            int mx = query(C, e[1] - 1) + 1;
            ans = max(mx, ans);
            update(C, e[1], mx);
        }

        return ans;
    }

    int query(vi &C, int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans = max(C[x], ans);
            x -= -x & x;
        }
        return ans;
    }

    void update(vi &C, int x, int y)
    {
        while (x < C.size())
        {
            C[x] = max(C[x], y);
            x += -x & x;
        }
    }
};