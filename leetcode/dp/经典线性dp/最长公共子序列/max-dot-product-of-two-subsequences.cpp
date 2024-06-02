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
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vi f1(n2 + 1), f2 = f1;
        int another = INT_MIN;
        REP(i, 1, n1)
        {
            REP(j, 1, n2)
            {
                int cur = nums1[i - 1] * nums2[j - 1];
                f1[j] = max({f1[j - 1], f2[j], f2[j - 1] + cur});
                another = max(another, cur);
            }
            swap(f1, f2);
        }
        int ans = f2.back();
        return ans == 0 ? another : ans;
    }
};
