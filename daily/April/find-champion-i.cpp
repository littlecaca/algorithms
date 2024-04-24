#include <vector>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        int winner = 0;
        for (int i = 1; i < n; ++i)
        {
            winner = grid[winner][i] == 1 ? winner : i;
        }
        return winner;
    }
};