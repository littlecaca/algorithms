#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<int> layer(height);
        layer[0] = triangle[0][0];

        for (int i = 1; i != height; ++i)
        {
            int width = triangle[i].size();
            
            layer[width - 1] = layer[width - 2] + triangle[i][width - 1];
            for (int j = width - 2; j != 0; --j)
            {
                layer[j] = min(layer[j - 1], layer[j]) + triangle[i][j];
            }
            layer[0] += triangle[i][0];
        }

        return *min_element(layer.begin(), layer.end());
    }
};

