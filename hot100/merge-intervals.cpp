#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>

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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int mark[(int)1e4 + 1][2] = {};
        for (auto &inte : intervals)
        {
            ++mark[inte[0]][0];
            ++mark[inte[1]][1];
        }
        vector<vector<int>> res;
        int left = 0, right = 0;
        int cur = 0;
        while (right <= (int)1e4)
        {
            cur += mark[right][0];
            if (mark[right][1] > 0)
            {
                cur -= mark[right][1];
                if (cur == 0)
                    res.push_back({left, right});
            }
            
            ++right;
            if (cur == 0)
                left = right;
        }
        return res;
    }
};