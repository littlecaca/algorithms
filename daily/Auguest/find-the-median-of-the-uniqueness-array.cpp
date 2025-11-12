#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>

using namespace std;

/// 二分法求中位数
/// (总数 + 1) / 2等于奇数个元素中位数所在位数，或偶数个元素第一个中位数所在位数。
/// O(nlogn)

int cnt[100001];

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int left = 1, right = nums.size();
        // 中位数前应该k个数字
        long long k = ((long long)right * (right + 1) / 2 + 1) / 2 - 1;
        // cout << "k " << k << endl;

        // 二分法查找第一个mid使countLess(nums, mid) > k
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            // cout << mid << " " << countLess(nums, mid) << endl;
            if (countLess(nums, mid) > k)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

    long long countLess(vector<int> &nums, int tar)
    {
        memset(cnt, 0, sizeof cnt);
        long long res = 0;
        int left = 0, right = 0;
        int count = 0;
        while (right < nums.size())
        {
            if (++cnt[nums[right]] == 1)
                ++count;
            while (count > tar)
            {
                if (--cnt[nums[left++]] == 0)
                    --count;
            }
            res += right - left + 1;
            ++right;
        }

        return res;
    }
};
