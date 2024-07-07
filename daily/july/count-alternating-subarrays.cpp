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
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll res = 0;
        int n = nums.size();
        vector<ll> fac(n + 1);

        fac[1] = 1;
        REP(i, 2, n)
            fac[i] = i + fac[i - 1];
        
        int last = -1;
        int cur = 0;
        for (auto i : nums)
        {
            if (i == last)
            {
                res += fac[cur];
                cur = 1;
            }
            else
                ++cur;
            last = i;
        }
        return res + fac[cur];
    }
};