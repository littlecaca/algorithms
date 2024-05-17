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
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vi &a, const vi &b) -> bool {
            return a[1] < b[1];
        });
        map<int, int, greater<int>> turned;
        int ans = 0;
        for (auto &task : tasks)
        {
            int start = task[0], end = task[1] + 1, duration = task[2];
            for (auto &p : turned)
            {
                if (p.first <= start)
                    break;
                duration -= p.first - p.second - max(0, start - p.second);
            }
            if (duration <= 0) continue;

            ans += duration;
            
            // 谨记循环不变量
            auto it1 = turned.begin(), it2 = turned.end();
            int right = end;
            while (duration > 0 && it1 != it2)
            {
                auto idle = right - it1->first;
                if (idle > duration)
                    right = right - duration;
                else
                {
                    right = it1->second;
                    ++it1;
                }
                duration = max(duration - idle, 0);
            }
            turned.erase(turned.begin(), it1);
            turned.insert({end, right - duration});

        }
        return ans;
    }
};