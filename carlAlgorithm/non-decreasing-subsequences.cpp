#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        backTracking(nums, 0, cur, res);
        return res;
    }

    void backTracking(vector<int> &nums, int start, vector<int> &cur, vector<vector<int>> &res)
    {
        if (cur.size() > 1)
        {
            res.push_back(cur);
        }
        unordered_set<int> used;
        for (int i = start; i < nums.size(); ++i)
        {
            if (used.find(nums[i]) != used.end()) continue;
            if (cur.empty() || nums[i] >= cur.back())
            {
                cur.push_back(nums[i]);
                backTracking(nums, i + 1, cur, res);
                cur.pop_back();
            }
            used.insert(nums[i]);
        }
    }
};