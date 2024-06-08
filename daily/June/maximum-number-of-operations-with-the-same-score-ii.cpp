#include <functional>
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
    
    int maxOperations(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        int n = nums.size();
        /**
         * 记忆化搜索
         */
        vvi mem(n, vi(n, -1));

        function<int(int, int, int)> check = [&](int left, int right, int last) -> int
        {
            if (left >= right) return 0;
            if (mem[left][right] != -1) return mem[left][right];

       
            int c1 = nums[left] + nums[right];
            int c2 = nums[left] + nums[left + 1];
            int c3 = nums[right] + nums[right - 1];
            int ans = 0;
            if (c1 == last)
                ans = max(ans, check(left + 1, right - 1, last) + 1);
            if (c2 == last)
                ans = max(ans, check(left + 2, right, last) + 1);
            if (c3 == last)
                ans = max(ans, check(left, right - 2, last) + 1);
            mem[left][right] = ans;
            return ans;
        };

        ans = max(check(left + 1, right - 1, nums[left] + nums[right]), ans);
        for (auto &line : mem)
            fill(line.begin(), line.end(), -1);
        ans = max(check(left + 2, right, nums[left] + nums[left + 1]), ans);
        for (auto &line : mem)
            fill(line.begin(), line.end(), -1);
        ans = max(check(left, right - 2, nums[right] + nums[right - 1]), ans);

        return ans + 1;
    }
};