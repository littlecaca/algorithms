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
    long long numberOfWays(string s) {
        ll one = 0, zero = 0;
        int oneC = 0, zeroC = 0;
        ll ans = 0;
        for (auto c : s)
        {
            if (c == '1')
            {
                ans += zero;
                one += zeroC;
                ++oneC;
            }
            else
            {
                ans += one;
                zero += oneC;
                ++zeroC;
            }
        }
        return ans;
    }
};