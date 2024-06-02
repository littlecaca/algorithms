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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        vi res;
        REP(i, 0, n - 1)
        {
            REP(j, 0, n - 1)
            {
                int cur = abs(grid[i][j]);
                int &tar = grid[(cur - 1) / n][(cur - 1) % n];
                if (tar < 0)
                    res.push_back(cur);
                else tar *= -1;
                sum += abs(cur);
            }
        }

        res.push_back((n * n + 1) * n * n / 2 - sum + res[0]);
        return res;
    }
};