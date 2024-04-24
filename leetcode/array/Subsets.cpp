#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        DFS(res, ans, 0, nums);
        return res;
    }

private:
    void DFS(vector<vector<int>> &res, vector<int> &ans, int start, vector<int> &nums)
    {
        res.push_back(ans);
        if (start == nums.size())
            return;
            
        for (int i = start; i != nums.size(); ++i)
        {
            ans.push_back(nums[i]);
            DFS(res, ans, i + 1, nums);
            ans.pop_back();
        }
    }
};