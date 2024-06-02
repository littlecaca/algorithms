#include <iostream>
#include <vector>
#include <cmath>

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
    int distributeCandies(int n, int limit) {
        int ans = 0;
        REP(i, 0, min(n, limit))
        {
            if (n - i > 2 * limit) continue;
            ans += min(limit, n - i) - max(0, n - i - limit) + 1;
        }
        return ans;
    }
};