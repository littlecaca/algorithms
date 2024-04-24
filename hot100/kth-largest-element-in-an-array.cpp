#include <functional>
#include <vector>

using namespace std;

class Solution
{
public:
    // 调整堆
    void adapt(vector<int> &nums, int head, int n)
    {
        int left = 2 * head, right = 2 * head + 1;
        int largest = head;
        if (left <= n && nums[left - 1] > nums[largest - 1])
            largest = left;
        if (right <= n && nums[right - 1] > nums[largest - 1])
            largest = right;
        if (largest != head)
        {
            swap(nums[largest - 1], nums[head - 1]);
            adapt(nums, largest, n);
        }
    }

    // 建立大顶堆
    void buildBigHeap(vector<int> &nums)
    {
        for (int i = nums.size() / 2; i >= 1; --i)
            adapt(nums, i, nums.size());
    }

    // 取堆顶元素
    int top(vector<int> &nums, int n)
    {
        int tar = nums[0];
        swap(nums[0], nums[n - 1]);
        adapt(nums, 1, n - 1);
        return tar;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        buildBigHeap(nums);
        int res;
        for (int i = 0; i < k; ++i)
        {
            res = top(nums, nums.size() - i);
        }
        return res;
    }
};