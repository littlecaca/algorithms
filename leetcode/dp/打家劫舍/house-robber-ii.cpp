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
    int rob(vector<int>& nums) {
        int a = 0, b = nums[0];
        int a2 = 0, b2 = 0;
        if (nums.size() == 1) return nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            auto temp = b;
            b = max(b, a + nums[i]);
            a = temp;

            temp = b2;
            b2 = max(b2, a2 + nums[i]);
            a2 = temp;
        }
        return max(b2, a);
    }
};