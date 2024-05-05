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
    vector<vector<int>> subsets(vector<int>& nums) {
        vvi res;
        vi trace;
        function<void(int)> backTracking = [&](int cur) {
            if (cur == nums.size())
            {
                res.push_back(trace);
                return;
            }
            backTracking(cur + 1);

            trace.push_back(nums[cur]);
            backTracking(cur + 1);
            trace.pop_back();

        };
        backTracking(0);
        return res;
    }
};