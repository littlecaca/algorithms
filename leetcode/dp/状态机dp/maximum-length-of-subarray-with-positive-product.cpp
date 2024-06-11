#include <functional>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        nums.push_back(0);
        int n = nums.size();
        vi record;
        int left = 0;
        REP(i, 0, n - 1)
        {
            if (nums[i] < 0)
                record.push_back(i);
            else if (nums[i] == 0)
            {
                if (record.size() & 1)
                    ans = max({ans, record.back() - left, i - record.front() - 1});
                else
                    ans = max(ans, i - left);
                left = i + 1;
                record.clear();
            }
        }
        return ans;
    }
};