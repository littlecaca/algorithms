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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vvi res(2);
        unordered_map<int, pair<int, int>> record;
        for (auto &match: matches)
        {
            auto winner = match[0], loser = match[1];
            ++record[winner].first;
            ++record[loser].second;
        }

        for (auto &re : record)
        {
            if (re.second.second == 0)
                res[0].push_back(re.first);
            if (re.second.second == 1)
                res[1].push_back(re.first);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};