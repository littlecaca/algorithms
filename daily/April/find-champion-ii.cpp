#include <vector>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n);
        for (auto &edge : edges)
        {
            ++degrees[edge[1]];
        }
        int count = 0;
        int cham;
        for (int i = 0; i < n; ++i)
        {
            if (degrees[i] == 0)
            {
                ++count;
                cham = i;
            }
        }
        if (count > 1)
            return -1;
        return cham;
    }
};