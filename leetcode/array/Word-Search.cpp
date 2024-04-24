#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        if (word.size() == 0) return true;
        int height = board.size(), width = board[0].size();
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                bool res = DFS(board, i, j, height, width, visited, word, 0);
                if (res) return res;
            }
        }
        return false;
    }

private:
    vector<vector<int>> direct{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool DFS(vector<vector<char>>& board, int x, int y, int height, int width, vector<vector<bool>> &visited, string &word, int index) 
    {
        if (board[x][y] != word[index]) return false;
        if (index == word.size() - 1) return true;

        visited[x][y] = true;

        for (const auto &dir : direct)
        {
            int nx = x + dir[0];
            int ny = y + dir[1] ;
            if (nx >= 0 && nx < height && ny >= 0 && ny < width)
            {
                if (!visited[nx][ny])
                {
                    bool res = DFS(board, nx, ny, height, width, visited, word, index + 1);
                    if (res) return res;
                }
            }
        }

        visited[x][y] = false;
        return false;
    }
};