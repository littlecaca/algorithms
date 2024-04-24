#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> seats;
        int res = 0;
        for (int i = 0; i != row.size(); ++i)
        {
            seats[row[i]] = i;
        }

        for (int i = 0; i != row.size(); i += 2)
        {
            int &first = row[i], &second = row[i + 1];
            if (first % 2 == 0 && first + 1 != second)
            {
                int t = seats[first + 1];
                int temp = row[t];
                row[t] = second;
                seats[second] = t;
                second = temp;
                
                ++res;
            }

            if (first % 2 != 0 && first - 1 != second)
            {
                int t = seats[first - 1];
                int temp = row[t];
                row[t] = second;
                seats[second] = t;
                second = temp;
                ++res;
            }
        }
        return res;
    }
};