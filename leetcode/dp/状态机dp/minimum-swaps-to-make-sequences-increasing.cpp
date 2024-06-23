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
#define INF 0x3f3f3f3f

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        /**
         * c1_i, c2_i分别表示前i个严格递增时，第i个元素不交换和交换时的最小操作次数
         */
        int c1 = 0, c2 = 1;

        int n = nums1.size();

        REP(i, 1, n - 1)
        {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
            {
                if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
                {
                    // 可交换可不交换
                    c1 = min(c1, c2);
                    c2 = c1 + 1;
                }
                else
                {
                    // 必须不能交换
                    c2 = c2 + 1;
                }
            }
            else
            {
                // 必须交换
                int t = c1;
                c1 = c2;
                c2 = t + 1;
            }
        }   
        return min(c1, c2);
    }
};