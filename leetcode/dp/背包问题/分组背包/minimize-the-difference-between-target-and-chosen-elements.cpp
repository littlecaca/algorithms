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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        vi dp1(target + 1), dp2 = dp1;

        REP(i, 0, target)
            dp1[i] = dp2[i] = i;
        
        REP(i, 0, m - 1)
        {
            _REP(j, target, 0)
            {
                dp1[j] = INT_MAX;
                REP(k, 0, n - 1)
                    dp1[j] = min(dp1[j], dp2[max(0, j - mat[i][k])] + max(0, mat[i][k] - j));
            }
            swap(dp1, dp2);
        }
        return dp2.back();
    }
};
