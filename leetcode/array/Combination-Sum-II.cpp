#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combine;
        DFS(candidates, res, combine, 0, target);
        return res;
    }

private:
    void DFS(const vector<int> &can, vector<vector<int>> &res, 
             vector<int> &combine, int start, int target) 
    {
        if (start == can.size()) return;
        
        
        int t = start + 1;
        while (t < can.size() && can[t] == can[start])
            ++t;
        DFS(can, res, combine, t, target);

        target -= can[start];
        combine.push_back(can[start]);

        if (target == 0)
        {
            res.push_back(combine);
        }
        else if (target > 0) {
            DFS(can, res, combine, start + 1, target);
        }
        else 
        {
            combine.pop_back();
            return;
        }

        combine.pop_back();
    }
};