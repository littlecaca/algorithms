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
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vi cols(n, INT_MIN);

        int ans = INT_MIN;
        for (int i = 0; i < m; ++i)
        {
            int mx = INT_MIN;
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    mx = cols[j] = -grid[i][j];
                    continue;
                }

                auto cur = grid[i][j];
                auto tar = max(mx, cols[j]) + cur;
                
                ans = max(ans, tar);
                // 考虑到可以从任意结点开始，也可以从当前结点开始
                tar = max(0, tar);

                mx = max(mx, tar - cur);
                cols[j] = max(cols[j], tar - cur);
            }
        }
        return ans;
    }
};