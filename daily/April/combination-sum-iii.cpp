#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> trace;
        function<void(int, int, int)> backTracking = [&](int k_r, int n_r, int cur) {
            if (n_r == 0 && k_r == 0)
            {
                res.push_back(trace);
                return;
            }
            if (n_r <= 0 || k_r <= 0)
                return;
            for (int i = cur; i <= 9; ++i)
            {
                trace.push_back(i);
                backTracking(k_r - 1, n_r - i, i + 1);
                trace.pop_back();
            }
            
        };
        backTracking(k, n, 1);
        return res;
    }
};