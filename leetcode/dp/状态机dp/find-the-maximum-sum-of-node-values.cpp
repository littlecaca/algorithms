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


class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        /**
         * 树形dp，难点在于如何进行状态的定义和转移
         * 
         * 定义r1, r2分别为操作和不操作x时，x的子树的最大和
         * 定义f1, f2分别为操作奇数次和偶数次子结点时，子结点的最大和
         */
        int n = nums.size();
        vvi graph(n);
        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<pair<ll, ll>(int, int)> dfs = [&](int x, int p) -> pair<ll, ll>
        {
            ll f1 = 0, f2 = INT_MIN, t;
            for (int child : graph[x])
            {
                if (child == p) continue;
                auto [r1, r2] = dfs(child, x);
                t = f1;
                f1 = max(f1 + r1, f2 + r2);
                f2 = max(t + r2, f2 + r1);
            }
            return {max(f1 + nums[x], f2 + (nums[x] ^ k)), max(f1 + (nums[x] ^ k), f2 + nums[x])};
        };

        return dfs(0, -1).first;
    }
};