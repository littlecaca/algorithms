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
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        vector<bool> f1(m + 1), f2(m + 1);
        f2[0] = true;
        REP(i, 1, n)
        {
            char tar = p[i - 1];
            if (f2[0] && tar == '*') f1[0] = true;
            else f1[0] = false;

            REP(j, 1, m)
            {
                if (tar == s[j - 1] || tar == '?')
                    f1[j] = f2[j - 1];
                else if (tar == '*')
                    f1[j] = f1[j - 1] || f2[j];
                else f1[j] = false;
            }
            swap(f1, f2);
        }
        return f2.back();
    }
};
