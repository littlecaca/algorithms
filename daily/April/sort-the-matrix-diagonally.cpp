#include <climits>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;

template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        // 简单插入算法，时间复杂度O(n2)
        auto insert_sort = [&] (int x, int y) -> void {
            while (x < m && y < n)
            {
                int i, j;
                int tar = mat[x][y];
                for (i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
                {
                    if (tar < mat[i][j])
                        mat[i + 1][j + 1] = mat[i][j];
                    else break;
                }
                mat[i + 1][j + 1] = tar;
                ++x; ++y;
            }
        };

        for (int i = 0; i < m; ++i)
            insert_sort(i, 0);
        for (int j = 1; j < n; ++j)
            insert_sort(0, j);
        return mat;
    }
};