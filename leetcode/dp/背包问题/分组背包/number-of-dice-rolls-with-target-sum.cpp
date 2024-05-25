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
    int numRollsToTarget(int n, int k, int target) {
        constexpr int mod = 1e9 + 7;

        vi f(target + 1);
        f[0] = 1;
        REP(i, 1, n)
        {
            vi old_f = f;
            f[0] = 0;
            REP(j, 1, target)
            {
                f[j] = (old_f[j - 1] + f[j - 1]) % mod;
                if (j >= k + 1)
                    f[j] = (f[j] - old_f[j - k - 1] + mod) % mod;
            }
        }
        return f.back();
    }
};