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
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != s3.size()) return false;

        vector<bool> f(n2 + 1);
        f[0] = true;
        REP(i, 0, n1)
        {
            REP(j, 0, n2)
            {
                int tar = i + j - 1;
                if (j > 0 && s3[tar] == s2[j - 1] && f[j - 1])
                    f[j] = true;
                else if (i > 0 && s3[tar] == s1[i - 1] && f[j])
                    f[j] = true;
                else if (i != 0 || j != 0)
                    f[j] = false;
            }
        }
        return f.back();

    }
};