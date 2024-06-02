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
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vi record;
        int n = nums.size();
        REP(i, 0, n - 1)
        {
            int cur = nums[i];
            if (cur == x)
                record.push_back(i);
        }
        
        vi res;
        for (int q : queries)
        {
            if (q > record.size())
                res.push_back(-1);
            else
                res.push_back(record[q - 1]);
        }
        return res;

    }
};