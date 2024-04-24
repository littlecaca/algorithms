#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int left = intervals[0][0], right = intervals[0][1];
        for (size_t i = 1; i != intervals.size(); ++i)
        {
            auto &v = intervals[i];
            if (v[0] <= right)
            {
                right = max(right, v[1]);
            }
            else
            {
                res.push_back({left, right});
                left = v[0];
                right = v[1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};
