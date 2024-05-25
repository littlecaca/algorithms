#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <numeric>
#include <iostream>
#include <climits>
#include <forward_list>
#include <functional>

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

# define REP(i,a,b) for(int i = a; i <= b; ++i)
# define _REP(i,a,b) for(int i = a; i >= b; --i)
# define DEBUG(num) cout << "debug: " << num << endl;

template <typename T>
bool chmin(T &a, const T &b)
{
	if (a <= b) return false;
	a = b;
	return true;
}

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> record;

        int ans = 1;
        int left = 0, right = 1, n = nums.size();
        int count = 1;
        int cur_count = 1;
        ++record[nums[0]];
        while (right < n)
        {
            int cur = nums[right];
            if (cur == nums[left])
            {
                ++cur_count;
                ans = max(ans, cur_count);
            }
            ++record[cur];
            ++count;
            if (count - cur_count > k)
            {
                --count;
                --record[nums[left++]];
                cur_count = record[nums[left]];
                ans = max(cur_count, ans);
            }
            ++right;
        }

        for (auto [i, c] : record)
            ans = max(ans, c);

        return ans;
    }
};