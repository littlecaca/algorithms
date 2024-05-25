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
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vi f1(k + 1, INT_MIN);
        f1[0] = 0;

        REP(i, 0, n - 1)
        {
            auto &coins = piles[i];
            int cnt = coins.size();

            _REP(j, k, 1)
            {
                int sum = 0;
                int r = min(j, cnt);
                
                REP(q, 1, r)
                {
                    sum += coins[q - 1];
                    f1[j] = max(f1[j], f1[j - q] + sum);
                }
            }
        }

        return f1.back();
    }
};