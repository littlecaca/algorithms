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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = worker.size(), n = profit.size();
        vi ordered(n);
        for (int i = 0; i < n; ++i)
            ordered[i] = i;
        sort(ordered.begin(), ordered.end(), [&](int a, int b) -> bool {
            return profit[a] > profit[b];
        });

        sort(worker.begin(), worker.end(), greater<int>());

        int ans = 0;
        for (int i = 0, j = 0; i < m && j < n; ++i)
        {
            while (j < n && worker[i] < difficulty[ordered[j]])
                ++j;
            if (j == n) break;
            ans += profit[ordered[j]];
        }

        return ans;
    }
};