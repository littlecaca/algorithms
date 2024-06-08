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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vi f(n), trace(n, -1);
        vi res;
        int mx = 0;
        int ans = 0;
        REP(i, 0, n - 1)
        {
            int cur = nums[i];
            int old = 0;
            REP(j, 0, i - 1)
                if (cur % nums[j] == 0)
                    if (f[j] > old)
                    {
                        old = f[j];
                        trace[i] = j;
                    };
            f[i] = old + 1;
            if (f[i] > mx)
            {
                mx = f[i];
                ans = i;
            }
        }

        while (ans != -1)
        {
            res.push_back(nums[ans]);
            ans = trace[ans];
        }
        return res;
    }
};