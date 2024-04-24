#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 使用两次二分查找即可
        vector<int> firstCol(matrix.size());
        for (int i = 0; i < matrix.size(); ++i)
            firstCol[i] = matrix[i][0];
        auto edge = upper_bound(firstCol.begin(), firstCol.end(), target);
        if (edge == firstCol.begin()) return false;
        --edge;
        int row = edge - firstCol.begin();
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};