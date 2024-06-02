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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m_sum = accumulate(rolls.begin(), rolls.end(), 0);
        int n_sum = mean * (rolls.size() + n) - m_sum;
        int d = n_sum / n, re = n_sum % n;
        if (n_sum > 6 * n || n_sum < n) return {};
        vector<int> res(n);

        REP(i, 1, n)
        {
            if (re)
            {
                res[i - 1] = d + 1;
                --re;
            }
            else
                res[i - 1] = d;
        }
        return res;

    }
};