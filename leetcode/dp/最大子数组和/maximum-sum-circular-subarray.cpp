#include <array>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mna = nums[0], mxa = nums[0];
        int mn = 0, mx = 0;
        int sum = 0;
        for (auto n : nums)
        {
            sum += n;
            mn += n;
            mx += n;
            mna = min(mna, mn);
            mxa = max(mxa, mx);
            if (mn > 0) mn = 0;
            if (mx < 0) mx = 0;
        }
        return mxa < 0 ? mxa : max(mxa, sum - mna);
    }
};
