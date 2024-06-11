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
    long long maxScore(vector<int>& nums, int x) {
        ll odd = 0, even = 0;
        if (nums[0] & 1)
            even = INT_MIN;
        else
            odd = INT_MIN;

        for (int n : nums)
        {
            if (n & 1)
                odd = max(odd, even - x) + n;
            else
                even = max(even, odd - x) + n;
        }
        return max(odd, even);
    }
};