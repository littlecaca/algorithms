#include <unordered_set>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>

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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        static const vpii ways = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        queue<pii> que;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2) que.push({i, j});

        int ans = -1;
        while (!que.empty())
        {
            ++ans;
            int size = que.size();
            while (size--)
            {
                auto rotten = que.front();
                que.pop();
                for (auto &way : ways)
                {
                    int nx = rotten.first + way.first, ny = rotten.second + way.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        que.push({nx, ny});
                    }
                }
            }
        }

        for (auto &line : grid)
            for (auto mark : line)
                if (mark == 1) return -1;
        
        return max(ans, 0);
    }
};