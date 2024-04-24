#include <vector>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i <= right; )
        {
            if (nums[i] == 0)
            {
                auto temp = nums[left];
                nums[left++] = 0;
                nums[i] = temp;
                ++i;
            }
            else if (nums[i] == 2)
            {
                auto temp = nums[right];
                nums[right--] = 2;
                nums[i] = temp;
            }
            else if (nums[i] == 1)
                ++i;
        }
    }
};

int main(int argc, char const *argv[])
{   
    vector<int> v{2,0,1};
    Solution().sortColors(v);
    return 0;
}
