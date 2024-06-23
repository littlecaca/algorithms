#include <unordered_set>
#include <stack>
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

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const vi &lhs, const vi & rhs) -> bool {
            return lhs[0] > rhs[0];
        });
        int n = items.size();

        unordered_set<int> record;
        ll sum = 0;
        ll ans = 0;
        stack<int> sta;
        REP(i, 0, k - 1)
        {
            sum += items[i][0];
            if (record.count(items[i][1]))
                sta.push(items[i][0]);
            record.insert(items[i][1]);
        }
        ans = sum + record.size() * record.size();

        REP(i, k, n - 1)
        {
            if (!record.count(items[i][1]) && !sta.empty())
            {
                auto temp = sta.top(); sta.pop();
                sum += items[i][0] - temp;
                record.insert(items[i][1]);
                ans = max(ans, sum + (ll)record.size() * (ll)record.size());
            }
        }
        return ans;
    }
};