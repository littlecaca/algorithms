#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> record(101);
        // eratosthenes筛法
        for (int i = 2; i <= 100; ++i)
        {
            if (!record[i])
            {
                for (int j = i * 2; j <= 100; j += i)
                    record[j] = true;
            }
        }
        // 1既不是质数也不是合数
        record[1] = true;
        int left = 0, right = nums.size() - 1;
        while (record[nums[left]])
            ++left;
        while (record[nums[right]])
            --right;
        return right - left;
    }
};