#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = 0, i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums2[i] > nums1[j])
            {
                nums1[j + i + 1] = nums2[i];
                --i;
            }
            else
            {
                nums1[j + i + 1] = nums1[j];
                --j;
            }
        }

        while (i >= 0)
        {
            nums1[i] = nums2[i];
            --i;
        }
    }
};