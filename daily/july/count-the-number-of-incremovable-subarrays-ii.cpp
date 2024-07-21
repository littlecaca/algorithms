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
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int left = INT_MAX, right = INT_MIN;
        REP(i, 1, n - 1)
        {
            if (nums[i] <= nums[i - 1])
            {
                left = min(left, i);
                right = max(right, i - 1);
            }
        }
        ll ans = 0;
    
        int rleast = max(0, right);
        int l = left;
        _REP(r, n - 1, rleast)
        {
            l = min(l, r);
            while (r < n - 1 && l > 0 && nums[l - 1] >= nums[r + 1])
                --l;
            ans += l + 1;
        }
        return ans;
    }
};
