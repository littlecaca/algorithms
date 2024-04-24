#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> record;
        record.push_back({nums[0], 0});
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            int n = record.front().first + nums[i];
            while (!record.empty() && n > record.back().first)
            {
                record.pop_back();
            }
            
            record.push_back({n, i});
            if (record.front().second <= i - k)
                record.pop_front();
            
        }
        return record.front().first + nums.back();
    }
};