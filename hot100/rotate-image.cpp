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
    void rotate(vector<vector<int>>& matrix) {
        int m = 0, n = matrix.size() - 1;
        while (m < n)
        {
            for (int i = m; i < n; ++i)
            {
                int x = i , y = matrix.size() - m - 1, pre = matrix[m][i];
                
                for (int j = 0; j < 4; ++j)
                {
                    int temp = matrix[x][y];
                    matrix[x][y] = pre;
                    pre = temp;
                    int t = x;
                    x = y, y = matrix.size() - t - 1; 
                }
            }
            ++m; --n;
        }
    }
};