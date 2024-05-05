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
    vector<vector<int>> permute(vector<int>& nums) {
        vvi res;
        vector<bool> visited(nums.size());
        vi trace;
        function<void(void)> backTracking = [&]() {
            bool is_finished = true;
            for (int i = 0; i < nums.size(); ++i)
            {
                if (!visited[i])
                {
                    is_finished = false;
                    trace.push_back(nums[i]);
                    visited[i] = true;
                    backTracking();
                    if (is_finished) res.push_back(trace);
                    visited[i] = false;
                    trace.pop_back();
                }
            }
            if (is_finished) res.push_back(trace);
        };
        backTracking();
        return res;
    }
};