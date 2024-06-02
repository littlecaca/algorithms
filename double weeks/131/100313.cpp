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
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> record;
        unordered_map<int, int> colors;
        int cnt = 0;
        vi res;
        for (auto &que : queries)
        {
            int index = que[0], color = que[1];
            // delete
            if (colors.count(index))
            {
                int c = colors[index];
                if (--record[c] == 0)
                    --cnt;
            }
            // add
            colors[index] = color;
            if (++record[color] == 1)
                ++cnt;
            res.push_back(cnt);
        }
        return res;
    }
};