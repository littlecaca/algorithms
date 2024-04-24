#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 题目要求O(log(m + n))的时间复杂度，那么只能寻求二分法
        int m = nums1.size(), n = nums2.size();
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
            
        
        // 开始二分法，j = (m + n + 1) / 2 - i;
        int left = 0, right = m;
        int i, j;
        int res1, res2;

        while (left <= right)
        {
            i = (left + right) / 2;
            j = (m + n + 1) / 2 - i;
            
            if (i != 0 && j != n && nums1[i - 1] > nums2[j])
            {
                right = i - 1;
            }
            else if (j != 0 && i != m && nums2[j - 1] > nums1[i])
            {
                left = i + 1;
            }
            else
            {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j - 1];
                else if (j == 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                
                int minRight = 0;
                if (i == m)
                    minRight = nums2[j];
                else if (j == n)
                    minRight = nums1[i];
                eolse

            }
        }
    }
};