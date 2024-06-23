#include <unordered_set>
#include <stack>
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
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int up = 'a' + k - 1;
        auto ispalin = [&](int i, int c) -> bool {
            if (i - 1 >= 0 && c == s[i - 1])
                return false;
            if (i - 2 >= 0 && c == s[i - 2])
                return false;
            return true;
        };

        auto fill = [&](int i) -> void {
            REP(j, i, n - 1)
            {
                REP(m, 'a', up)
                {
                    if (ispalin(j, m))
                    {
                        s[j] = m;
                        break;
                    }
                }
            }
        };

        _REP(i, n - 1, 0)
        {
            REP(j, s[i] + 1, up)
            {
                if (ispalin(i, j))
                {
                    s[i] = j;
                    fill(i + 1);
                    return s;
                }
            }
        }

        return "";
    }
};
