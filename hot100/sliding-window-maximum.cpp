#include <vector>
#include <deque>

using namespace std;




class Solution {
public:
    // 单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;

        int left = 0, right = 0;
        while (right < nums.size())
        {
            while (!que.empty() && nums[right] >= nums[que.back()])
            {
                que.pop_back();
            }
            que.push_back(right);
            if (right >= k - 1)
            {
                if (right > k - 1)
                {
                    if (left == que.front())
                    {
                        que.pop_front();
                    }
                    ++left;
                }
                res.push_back(nums[que.front()]);
            }
            ++right;
        }
        return res;
    }
};