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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cols(n);
        vector<int> left(2 * n - 1);
        vector<int> right(2 * n - 1);
        vector<string> trace(n, string(n, '.'));
        function<void(int)> backTracking = [&](int x) -> void {
            if (x >= n)
            {
                res.push_back(trace);
                return;
            }

            for (int i = 0; i < n; ++i)
            {
                int left_index = n - x + i - 1;
                int right_index = x + i;
                if (cols[i] == 0 && left[left_index] == 0 && right[right_index] == 0)
                {
                    trace[x][i] = 'Q';
                    cols[i] = 1;
                    left[left_index] = 1;
                    right[right_index] = 1;
                    backTracking(x + 1);
                    trace[x][i] = '.';
                    cols[i] = 0;
                    left[left_index] = 0;
                    right[right_index] = 0;
                }
            }
        };

        backTracking(0);
        return res;
    }
};