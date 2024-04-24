#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int height = matrix.size(),
            width = matrix[0].size();
        
        for (size_t i = 0; i != height / 2; ++i)
        {
            for (size_t j = i; j != width - i - 1; ++j)
            {
                int k = 4;
                int val = matrix[i][j];
                int cx = i, cy = j;
                while (k--)
                {
                    int temp = matrix[tx(cx, cy)][ty(height, cx, cy)];
                    matrix[tx(cx, cy)][ty(height, cx, cy)] = val;
                    val = temp;
                    int _x = cx;
                    cx = tx(cx, cy);
                    cy = ty(height, _x, cy);
                }
            }
        }
    }
private:
    inline int tx(int x, int y)
    {
        return y;
    }
    inline int ty(int height, int x, int y)
    {
        return height - x - 1;
    }
};

