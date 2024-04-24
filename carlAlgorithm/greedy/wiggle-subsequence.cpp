#include <vector>

using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count = 1;
        int flag = 0;
        for (int i = 1; i != nums.size(); ++i)
        {
            int temp = nums[i] - nums[i - 1];
          
            if (temp == 0) continue;

            if (flag * temp <= 0)
            {
                flag = temp;
                ++count;
            }
        }
        return count;
    }
};