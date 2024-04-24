#include <algorithm>
#include <vector>

using namespace std;    


class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int obtainable = 0;
        int ans = 0;
        int cur = 0;
        sort(coins.begin(), coins.end());

        while (obtainable < target)
        {
            if (cur < coins.size())
            {
                if (obtainable + 1 < coins[cur])
                {
                    obtainable += obtainable + 1;
                    ++ans;
                }
                else
                {
                    obtainable += coins[cur];
                    ++cur;
                }
            }
            else
            {
                obtainable += obtainable + 1;
                ++ans;
            }
        }
        return ans;
    }
};