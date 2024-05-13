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
    int maxAbsoluteSum(vector<int>& nums) {
        int posi = 0, nega = 0;
        int ans = 0;

        for (auto n : nums)
        {
            posi += n;
            nega += n;
            ans = max({ans, abs(posi), abs(nega)});
            if (posi < 0) posi = 0;
            if (nega > 0) nega = 0;
        }
        return ans;

    }
};