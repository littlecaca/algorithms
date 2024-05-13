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
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(n);
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i)
        {
            sum1 += nums1[i];
            sum2 += nums2[i];
            diff[i] = nums1[i] - nums2[i];
        }

        int mxa = diff[0], mna = diff[0];
        int mx = 0, mn = 0;
        for (auto num : diff)
        {
            mx += num;
            mn += num;
            mxa = max(mxa, mx);
            mna = min(mna, mn);
            if (mx < 0) mx = 0;
            if (mn > 0) mn = 0;
        }
        return max({sum1, sum2, sum1 - mna, sum2 + mxa});
    }
};