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
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vvi record(n, vi(2));

        int ans = 0;
        REP(i, 0, n - 1)
        {
            int gr = 0, le = 0;
            int cur = rating[i];
            REP(j, 0, i - 1)
            {
                if (cur > rating[j])
                {
                    ++gr;
                    ans += record[j][0];
                }
                else
                {
                    ++le;
                    ans += record[j][1];
                }
            }
            record[i][0] = gr;
            record[i][1] = le;
        }
        return ans;
    }
};