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

struct Node
{
    int l, r, mx;
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        /**
         * 使用线段树
        */
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<Node> C(4 * (mx + 1));

        build(C, 1, 0, mx);

        int ans = 0;
        for (int i : nums)
        {
            int old = query(C, 1, max(i - k, 0), i - 1);
            ans = max(ans, old + 1);
            update(C, 1, i, old + 1);
        }
        return ans;
    }

    void build(vector<Node> &C, int p, int l, int r)
    {
        C[p].l = l; C[p].r = r; C[p].mx = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(C, 2 * p, l, mid);
        build(C, 2 * p + 1, mid + 1, r);
    }

    void update(vector<Node> &C, int p, int x, int v)
    {
        if (C[p].l == C[p].r)
        {
            C[p].mx = max(v, C[p].mx);
            return;
        }

        int mid = (C[p].l + C[p].r) >> 1;
        if (x <= mid)
            update(C, 2 * p, x, v);
        else 
            update(C, 2 * p + 1, x, v);
        
        C[p].mx = max(C[2 * p].mx, C[2 * p + 1].mx);
    }
    
    int query(vector<Node> &C, int p, int l, int r)
    {
        if (l <= C[p].l && r >= C[p].r)
            return C[p].mx;
        
        int mx = 0;
        int mid = (C[p].l + C[p].r) >> 1;
        if (l <= mid)
            mx = max(mx, query(C, 2 * p, l, r));
        if (r > mid)
            mx = max(mx, query(C, 2 * p + 1, l, r));
        return mx;
    }
};

