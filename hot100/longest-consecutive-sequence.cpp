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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        for (const int &n : nums)
            record.insert(n);
        int ans = 0;
        for (const int &n : nums)
        {
            if (!record.count(n - 1))
            {
                int cur = 1;
                for (int j = n + 1; record.count(j); ++j)
                {
                    ++cur;
                }
                ans = max(ans, cur);
            }
        }
        return ans;

    }
};
