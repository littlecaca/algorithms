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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0];
        int cnt = 0;
        for (int div : divisors)
        {
            int cur = 0;
            for (int n : nums)
            {
                if (n % div == 0)
                    ++cur;
            }
            if (cur > cnt || (cur == cnt && div < ans))
            {
                cout << cur << ", " << cnt << endl;
                cnt = cur;
                ans = div;
            }
        }
        return ans;
    }
};