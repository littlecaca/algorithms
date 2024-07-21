#include <unordered_set>
#include <climits>
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
    bool canSortArray(vector<int>& nums) {
        vpii record;
        int n = nums.size();
        REP(i, 0, n - 1)
        {
            record.emplace_back(nums[i], i);
        }
        sort(record.begin(), record.end());
        REP(i, 0, n - 1)
        {
            int left = i;
            auto right = record[left].second;
            if (left > right)
                swap(left, right);
            auto tar = count(nums[left]);
            REP(k, left + 1, right)
            {
                if (count(nums[k]) != tar)
                    return false;
            }
        }
        return true;
    }

    int count(int x)
    {
        int ans = 0;
        while (x > 0)
        {
            if (x & 1)
                ++ans;
            x >>= 1;
        }
        return ans;
    }
};