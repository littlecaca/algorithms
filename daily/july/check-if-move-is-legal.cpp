#include <unordered_set>
#include <climits>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}


class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        static vpii ways = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };
        char tar = color == 'W' ? 'B' : 'W';
        for (auto [x, y] : ways)
        {
            int nx = rMove + x;
            int ny = cMove + y;
            int cnt = 0;
            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == tar)
            {
                nx += x; ny += y;
                ++cnt;
            }
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == color && cnt > 0)
                return true;
        }
        return false;
    }
};