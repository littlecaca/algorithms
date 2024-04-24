#include <deque>
#include <queue>
#include <vector>

using namespace std;


class MyQueue 
{
public:
    void push(int tar)
    {
        while (!que.empty() && tar > que.back())
        {
            que.pop_back();
        }
        que.push_back(tar);
    }
    
    void pop()
    {
        que.pop_front();
    }

    int front() const 
    {
        return que.front();
    }

    
private:
    deque<int> que;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        int large = nums[0], i = 1;

        for (i = 0; i != k; ++i)
            que.push(nums[i]);

        res.push_back(que.front());
        
        while (i != nums.size())
        {
            que.push(nums[i]);
            if (nums[i - k] == que.front())
                que.pop();
            res.push_back(que.front());
            ++i;
        }
        return res;
    }
};
