
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
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        static vector<pair<int, int>> directions = {
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
        };
        function<bool(int, int, int)> backTracking = [&](int x, int y, int index) -> bool {
            if (index == word.size() - 1) return true;
            visited[x][y] = true;
            char tar = word[++index];
            for (auto &dir : directions)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && board[nx][ny] == tar && backTracking(nx, ny, index))
                {
                    return true;
                }
            }
            visited[x][y] = false;
            return false;
        };

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0] && backTracking(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};