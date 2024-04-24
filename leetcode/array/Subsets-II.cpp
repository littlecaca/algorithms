#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        DFS(res, nums, 0, cur);
        return res;
    }
    
private:
    void DFS(vector<vector<int>> &res, vector<int> &nums, int index, vector<int> &cur)
    {
        if (index == nums.size())
        {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[index]);
        DFS(res, nums, index + 1, cur);
        cur.pop_back();

        while (index + 1 < nums.size() && nums[index + 1] == nums[index])
            ++index;
        DFS(res, nums, index + 1, cur);
    }
};