#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> record;
        for (auto i = nums3.begin(); i != nums3.end(); ++i)
        {
            for (auto j = nums4.begin(); j != nums4.end(); ++j)
            {
                ++record[*i + *j];
            }
        }
        for (auto i = nums1.begin(); i != nums1.end(); ++i)
        {
            for (auto j = nums2.begin(); j != nums2.end(); ++j)
            {
                count += record[-*i - *j];
            }
        }
        return count;
    }
};