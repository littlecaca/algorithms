#include <vector>

using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int max_unhappy = 0;
        int total = 0;
        int cur = 0;
        for (int left = 0, right = 0; right < grumpy.size(); ++right)
        {
            if (grumpy[right])
            {
                cur += customers[right];
                max_unhappy = max(max_unhappy, cur);
            }
            else
            {
                total += customers[right];
            }

            if (right - left + 1 == minutes)
            {
                if (grumpy[left])
                {
                    cur -= customers[left];
                }
                ++left;
            }
        }
        return total + max_unhappy;
    }
};