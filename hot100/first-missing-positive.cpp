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
    int firstMissingPositive(vector<int>& nums) {
        for (auto n : nums)
        {
            while (n >= 1 && n <= nums.size() && nums[n - 1] != n)
            {
                int temp = nums[n - 1];
                nums[n - 1] = n;
                n = temp;
            }
        }

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        return nums.size() + 1;
    }
};