#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {

    }

    int backTracking(vector<vector<char>> &seats, int start_x, int start_y)
    {
        int height = seats.size(), width = seats[0].size();
        if (start_y == width)
        {
            ++start_x;
            start_y = 0;
        }
        if (start_x == height)
            return 0;
        
        int res = backTracking(seats, start_x, start_y + 1);
        if (isValid(seats, start_x, start_y))
        {
            seats[start_x][start_y] = '_';
            res = max(res, 1 + backTracking(seats, start_x, start_y + 1));
            seats[start_x][start_y] = '.';
        }
        return res;
    }

    bool isValid(vector<vector<char>> &seats, int start_x, int start_y)
    {
        if (seats[start_x][start_y] != '.') return false;
        if (start_x > 0)
        {
            if (start_y > 0 && seats[start_x - 1][start_y - 1] == '_')
                return false;
            if (start_y < seats[0].size() - 1 && seats[start_x - 1][start_y + 1] == '_')
                return false;
            fill()


        }
        
    }
};