#include <climits>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}

#define INF -0x3f3f3f3f - 1

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        /**
         * 状态机
         */
        int s1 = INF, s2 = INF;
        int ans = INF;
        for (int n : arr)
        {
            int t = s1;
            s1 = max(n, s1 + n);
            s2 = max(s2 + n, t);
            ans = max({ans, s2, s1});
        }
        return ans;
    }
};