#include <vector>

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 1;
        int flag = 0;
        int pre_candy = 1;
        int peak = 0;
        for (int i = 1; i != ratings.size(); ++i)
        {
            int temp = ratings[i] - ratings[i - 1];
            if (temp == 0)
            {
                if (peak != 0 && pre_candy >= peak)
                    count += pre_candy - peak + 1;
                peak = 0;
                flag = 0;
                pre_candy = 1;
            }
            else if (temp * flag < 0)
            {
                if (temp < 0)
                {
                    peak = pre_candy;
                    pre_candy = 1;
                }
                else
                {
                    if (peak != 0 && pre_candy >= peak)
                        count += pre_candy - peak + 1;
                    pre_candy = 2;
                }
            }
            else
                ++pre_candy;    
            
            flag = temp;
            count += pre_candy;
        }

        if (flag < 0 && peak != 0 && pre_candy >= peak)
            count += pre_candy - peak + 1;
        return count;
    }
};