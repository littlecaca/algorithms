#include <vector>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_sum = 0;
        int total_sum = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            int j = gas[i] - cost[i];
            cur_sum += j;
            total_sum += j;
            if(cur_sum < 0)
            {
                start = i + 1;
                cur_sum = 0;
            }
        }

        return total_sum < 0 ? -1 : start;
    }
};