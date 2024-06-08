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
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vi dp(4);
        REP(i, 1, n)
        {
            int j = nums[i - 1];
            dp[j] = *max_element(dp.begin(), dp.begin() + j + 1) + 1;
            
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};