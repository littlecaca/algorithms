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
    int minimumDeleteSum(string s1, string s2) {
		int n1 = s1.size(), n2 = s2.size();
		vi f1(n2 + 1), f2 = f1;
		REP(i, 1, n2)
			f2[i] = f2[i - 1] + s2[i - 1];

		int sum = 0;
		REP(i, 1, n1)
		{
			char c1 = s1[i - 1];
			sum += c1;
			f1[0] = sum;
			REP(j, 1, n2)
			{
				char c2 = s2[j - 1];
				if (c1 == c2)
					f1[j] = f2[j - 1];
				else
					f1[j] = min(f1[j - 1] + c2, f2[j] + c1);
			}
			swap(f1, f2);
		}
		return f2.back();

    }
};