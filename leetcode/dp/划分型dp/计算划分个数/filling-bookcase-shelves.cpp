#include <climits>
#include <string>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <iomanip>
#include <sstream>
#include <unordered_map>
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
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vi dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        REP(i, 1, n)
        {
            int mxht = 0,
                mxtk = 0;
            _REP(j, i, 1)
            {
                mxtk += books[j - 1][0];
                mxht = max(mxht, books[j - 1][1]);
                if (mxtk > shelfWidth) break;
                dp[i] = min(dp[i], dp[j - 1] + mxht);
            }
        }

        return dp.back();
    }
};