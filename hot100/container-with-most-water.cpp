#include <algorithm>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            ans = height[left] < height[right] ?
                (++left, max(ans, (right - left + 1) * height[left - 1])) :
                (--right, max(ans, (right - left + 1) * height[right + 1]));
        }
        return ans;
    }
};