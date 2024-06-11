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
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int ans = 0;
        REP(i, 0, m - 1)
        {
            REP(j, 0, n - 1)
            {
                if (board[i][j] == 'X')
                {
                    board[i][j] = '.';
                    REP(k, i + 1, m - 1)
                        if (board[k][j] == 'X') board[k][j] = '.';
                        else break;
                    REP(k, j + 1, n - 1)
                        if (board[i][k] == 'X') board[i][k] = '.';
                        else break;
                    ++ans; 
                }
            }
        }
        
        return ans;
    }
};