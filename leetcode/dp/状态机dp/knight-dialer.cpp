#include <numeric>
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
    int knightDialer(int n) {
        static const int mod = 1e9 + 7;
        vvi record = {
            {5, 7},
            {6, 8},
            {3, 7},
            {2, 8, 9},
            {},
            {0, 6, 9},
            {1, 5},
            {0, 2},
            {1, 3},
            {3, 5}
        };
        vector<ll> cur(10), last(10, 1);
    
        REP(i, 2, n)
        {   
            REP(j, 0, 9)
            {
                cur[j] = 0;
                for (int k : record[j])
                    cur[j] = (last[k] + cur[j]) % mod;
            }
            swap(cur, last);
        }
        int ans = 0;
        REP(i, 0, 9)
            ans = (ans + last[i]) % mod;
        return ans;
        
    }
};
