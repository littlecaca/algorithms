#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [](const vector<int> &v1, const vector<int> &v2) 
            { return v1[0] < v2[0]; });
        int count = 0;
        int left = points[0][0];
        for (int i = 0; i < points.size();)
        {
            ++count;
            while (i < points.size() && points[i][0] - left <= w)
            {
                ++i;
            }
            if (i < points.size())
                left = points[i][0];
        }
        return count;
    }
};