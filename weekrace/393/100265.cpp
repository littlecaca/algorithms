#include <vector>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right && !isPrime(nums[left]))
        {
            ++left;
        }

        while (left <= right && !isPrime(nums[right]))
        {
            --right;
        }
        return right - left;
    }

    bool isPrime(int n)
    {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
};