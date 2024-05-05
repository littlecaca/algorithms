#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> trace;
        
        function<void(int,int)> back_tracking = [&](int cur, int tar) -> void {
            if (tar < 0) return;
            if (tar == 0)
            {
                res.push_back(trace);
                return;
            }
            for (int i = cur; i < candidates.size(); ++i)
            {
                trace.push_back(candidates[i]);
                back_tracking(i, tar - candidates[i]);
                trace.pop_back();
            }
        };
        back_tracking(0, target);
        return res;
    }
};