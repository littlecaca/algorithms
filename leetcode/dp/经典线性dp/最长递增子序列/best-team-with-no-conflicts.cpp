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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vpii record;
        /**
         * 这里先对年龄进行排序，再对分数进行排序，可以在O(n2)时间复杂度完成，
         * 但是要想用树状数组或者线段树进行优化，最好是先排序分数，因为年龄的数值范围较小，
         * 节省空间。
        */

        // REP(i, 0, n - 1)
        //     record.push_back({ages[i], scores[i]});
        
        // sort(record.begin(), record.end());

        // int ans = 0;
        // vi f(n);
        // REP(i, 0, n - 1)
        // {
        //     int cur = record[i].second;
        //     int old = 0;
        //     _REP(j, i - 1, 0)
        //         if (cur >= record[j].second)
        //             old = max(f[j], old);
        //     f[i] = old + cur;
        //     ans = max(ans, f[i]);
        // }

        // return ans;

        /**
         * 采用树状数组保存0-x年龄段上分数取得最大值的最后一位队员
        */
        REP(i, 0, n - 1)
            record.push_back({scores[i], ages[i]});
        
        sort(record.begin(), record.end());
        vi C(1001);
        int ans = 0;
        for (auto &p : record)
        {
            int mx = query(C, p.second) + p.first;
            ans = max(ans, mx);
            update(C, p.second, mx);
        }
        return ans;
    }

    int query(vi &C, int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans = max(ans, C[x]);
            x -= -x & x;
        }
        return ans;
    }

    void update(vi &C, int x, int s)
    {
        while (x < C.size())
        {
            C[x] = max(C[x], s);
            x += -x & x;
        }
    }
};
