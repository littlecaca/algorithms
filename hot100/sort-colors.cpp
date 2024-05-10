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
    void sortColors(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (nums[right] == 0)
                swap(nums[right], nums[left++]);
            ++right;
        }
        right = left;
        while (right < nums.size())
        {
            if (nums[right] == 1)
                swap(nums[right], nums[left++]);
            ++right;
        }

    
    }
};