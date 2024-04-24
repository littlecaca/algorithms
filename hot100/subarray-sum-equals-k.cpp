#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // // 前缀和 --- O(n2) 容易超时
        // int sum = 0;
        // int ans = 0;
        // vector<int> prefix(nums.size() + 1);
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     sum += nums[i];
        //     prefix[i + 1] = sum;
        // }
        // for (int i = 1; i < prefix.size(); ++i)
        // {
        //     for (int j = 0; j < i; ++j)
        //     {
        //         if (prefix[i] - prefix[j] == k)
        //             ++ans;
        //     }
        // }
        // return ans;
        
        // 前缀和 + 哈希表优化
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> record;
        record[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (record.find(sum - k) != record.end())
                ans += record[sum - k];
            ++record[sum];
        }

        return ans;
    }
};