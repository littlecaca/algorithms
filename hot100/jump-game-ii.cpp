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
    int jump(vector<int>& nums) {
        int reach = 0;
        int step = 0;
        int cur = 0;
        while (reach < nums.size() - 1)
        {
            ++step;
            int new_reach = 0;
            for (int i = cur; i <= reach; ++i)
            {
                new_reach = max(new_reach, i + nums[i]);
            }
            cur = reach + 1;
            reach = new_reach;
        }
        return step;
    }
};