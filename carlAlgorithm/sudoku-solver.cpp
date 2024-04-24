#include <vector>

using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board, 0, 0);
    }

    bool backTracking(vector<vector<char>> &board, int x, int y)
    {
        int height = board.size(), width = board[0].size();
        if (y == width)
        {
            y = 0;
            ++x;
        }
        if (x == height) return true;

        if (board[x][y] != '.') 
        {
            return backTracking(board, x, y + 1);
        }
        else
        {
            vector<bool> status(10, false);
            int cell_x = (x / 3) * 3, cell_y = (y / 3) * 3;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    char digit = board[cell_x + i][cell_y + j];
                    if (digit != '.') status[digit - '0'] = true;
                }
            }
            for (int i = 0; i < 9; ++i)
            {
                char digit1 = board[i][y],
                     digit2 = board[x][i];
                if (digit1 != '.') status[digit1 - '0'] = true;
                if (digit2 != '.') status[digit2 - '0'] = true;
            }
            for (int i = 1; i < 10; ++i)
            {
                if (!status[i])
                {
                    board[x][y] = i + '0';
                    if (backTracking(board, x, y + 1))
                        return true;
                }
            }
            board[x][y] = '.';
            return false;
        }
    }
};