#include <vector>

using namespace std;

// 单调栈+常数优化

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        vector<int> stack, leftE(len), rightE(len);
        for (int i = 0; i < len; ++i)
        {
            bool flag = false;
            while (!stack.empty())
            {
                int j = stack.back();
                if (heights[j] < heights[i])
                {
                    leftE[i] = j;
                    flag = true;
                    break;
                }
                else
                {
                    stack.pop_back();
                    rightE[j] = i;
                }
            }
            if (!flag) leftE[i] = -1;
            stack.push_back(i);
        }

        for (auto k : stack)
        {
            rightE[k] = len;
        }

        for (int k = 0; k < len; ++k)
        {
            res = max(res, (rightE[k] - leftE[k] - 1) * heights[k]);
        }
        return res;
    }
};