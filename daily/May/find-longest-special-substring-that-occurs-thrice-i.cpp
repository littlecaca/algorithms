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
    int maximumLength(string s) {
        int mx = -1;
        int cur = 1;
        vector<unordered_map<int, int>> record(26);
        REP(i, 1, s.size() - 1)
        {
            if (s[i] == s[i - 1])
                ++cur;
            else
            {
                if (++record[s[i - 1] - 'a'][cur] >= 3)
                    mx = max(mx, cur);
                else if (cur > 1 && (record[s[i - 1] - 'a'][cur - 1] += 2) >= 3)
                    mx = max(mx, cur - 1);
                else if (cur > 2)
                    mx = max(mx, cur - 2);
                cur = 1;
            }
        }
        int i = s.size();
        if (++record[s[i - 1] - 'a'][cur] >= 3)
            mx = max(mx, cur);
        else if (cur > 1 && (record[s[i - 1] - 'a'][cur - 1] += 2) >= 3)
            mx = max(mx, cur - 1);
        else if (cur > 2)
            mx = max(mx, cur - 2);
        return mx;
    }
};