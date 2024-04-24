#include <vector>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0;
        int max_profit = 0;
        int max_rotate = 0;
        int count = 0;
        if (boardingCost * 4 <= runningCost) return -1;
        
        for (int i = 0; i < customers.size() || count > 0; ++i)
        {
            if (i < customers.size())
                count += customers[i];
            int temp;
            if (count < 4)
            {
                temp = count;
                count = 0;
            }
            else
            {
                temp = 4;
                count -= 4;
            }
            profit += temp * boardingCost - runningCost;
            if (profit > max_profit)
            {
                max_profit = profit;
                max_rotate = i + 1;
            }
        }
        
        return max_profit <= 0 ? -1 : max_rotate;
    }
};