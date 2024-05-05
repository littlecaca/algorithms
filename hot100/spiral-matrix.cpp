#include <algorithm>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x1 = 0, y1 = 0, x2 = matrix.size() - 1, y2 = matrix[0].size() - 1;
        vi res;
        while (x1 <= x2 && y1 <= y2)
        {
            for (int i = y1; i <= y2; ++i)
                res.push_back(matrix[x1][i]);
            if (x1 == x2) break;

            for (int i = x1 + 1; i <= x2; ++i)
                res.push_back(matrix[i][y2]);
            if (y1 == y2) break;

            for (int i = y2 - 1; i >= y1; --i)
                res.push_back(matrix[x2][i]);
            for (int i = x2 - 1; i > x1; --i)
                res.push_back(matrix[i][y1]);
            ++x1; ++y1; --x2; --y2;
        }
        return res;

    }
};