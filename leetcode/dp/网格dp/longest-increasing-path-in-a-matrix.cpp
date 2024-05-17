#include <map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>

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
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 记忆化搜索 + 深度优先遍历
        vvi memory(m, vi(n));

        function<int(int, int)> search = [&](int x, int y) -> int {
            static const vpii ways = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}
            };
            if (memory[x][y] != 0) return memory[x][y];

            int neigh = 0;
            for (auto &way : ways)
            {
                int nx = x + way.first,
                    ny = y + way.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[x][y] < matrix[nx][ny])
                    neigh = max(neigh, search(nx, ny));
            }
            memory[x][y] = neigh + 1;
            return memory[x][y];
        };

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                ans = max(ans, search(i, j));
        }
        return ans;
    }
};