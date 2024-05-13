#include <array>
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
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int ans = 0;
        vector<int> record(27, INT_MIN);
        for (int i = 0; i < chars.size(); ++i)
            record[chars[i] - 'a' + 1] = vals[i];

        int cur = 0;
        for (auto c : s)
        {
            int index = c - 'a' + 1;
            cur += record[index] == INT_MIN ? index : record[index];
            ans = max(ans, cur);
            if (cur < 0)
                cur = 0;
        }
        return ans;
    }
};