#include <unordered_set>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>

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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        auto cal = [&](int p) -> int {
            auto a = points[p];
            return max(abs(a[0]), abs(a[1]));
        };
        auto compare = [&](int p1, int p2) -> bool {
            return cal(p1) > cal(p2);
        };
        priority_queue<int, vector<int>, decltype(compare)> que(compare);

        for (int i = 0; i < points.size(); ++i)
        {
            que.push(i);
        }

        unordered_map<char, int> record;
        int ans = 0;
        int count = 0;
        int last = -1;
        while (!que.empty())
        {
            auto tar = que.top();
            que.pop();

            int cur = cal(tar);
            if (cur == last)
                ++count;
            else
            {
                ans += count;
                count = 1;
            }
            last = cur;

            if (record.find(s[tar]) == record.end())
            {
                record.insert({s[tar], tar});
            }
            else return ans;
        }
        return ans + count;
    }
};