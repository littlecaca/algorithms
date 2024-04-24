#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int i = 1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;
        int count = n * n;
        int cur = 0;
        while (count--)
        {
            visited[x][y] = true;
            res[x][y] = i++;

            int pred_x = direct[cur][0] + x,
                pred_y = direct[cur][1] + y;
            if (pred_y < 0 || pred_x == n || pred_y == n || visited[pred_x][pred_y])
            {
                cur = (cur + 1) % 4;
            }
            x += direct[cur][0];
            y += direct[cur][1];
        }
        return res;
    }
};