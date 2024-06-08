#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>

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

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // 二分贪心
        vi f;
        int n = obstacles.size();
        vi ans(n);
        REP(i, 0, n - 1)
        {
            int ob = obstacles[i];
            auto res = upper_bound(f.begin(), f.end(), ob);
            ans[i] = (res - f.begin()) + 1;
            if (res == f.end())
                f.push_back(ob);
            else *res = ob;
        }
        return ans;
    }
};
