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
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = 0; ll sum = 0;
        for (auto n : milestones)
        {
            mx = max(n, mx);
            sum += n;
        }

        if (mx <= sum / 2)
            return sum;
        else
            return (sum - mx) * 2 + 1;
    }
};