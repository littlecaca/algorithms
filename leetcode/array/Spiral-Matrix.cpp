#include <vector>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size(), width = matrix[0].size();
        vector<int> res;
        int left = 0, right = width - 1, top = 0, bottom = height - 1;
        while (left <= right && top <= bottom)
        {
            int cx, cy;
            for (cy = left; cy <= right; ++cy)
            {
                res.push_back(matrix[top][cy]);
            }
            
            for (cx = top + 1; cx <= bottom; ++ cx)
            {
                res.push_back(matrix[cx][right]);
            }

            if (left < right && top < bottom)
            {
                for (cy = right - 1; cy != left; --cy)
                {
                    res.push_back(matrix[bottom][cy]);
                }

                for(cx = bottom; cx != top; --cx)
                {
                    res.push_back(matrix[cx][left]);
                }
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<int> m;
    Solution().spiralOrder(m);

    return 0;
}
