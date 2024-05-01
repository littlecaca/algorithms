#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>

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
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int base = min(height[left], height[right]);
        while (left < right)
        {
            int lh = height[left], rh = height[right];
            if (lh <= base)
            {
                ans += base - lh;
                ++left;
            }
            else if (rh <= base)
            {
                ans += base - rh;
                --right;
            }
            else
                base = min(lh, rh);
        }
        return ans;
    }
};