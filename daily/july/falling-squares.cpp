#include <unordered_set>
#include <climits>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include <stdlib.h>
#include <string.h>

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

#define SIZE 2000

struct ST
{
    int l, r;
    int mx;
    int mark;   // 延迟标记
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define mx(x) tree[x].mx
    #define mark(x) tree[x].mark
} tree[4 * SIZE];

void build(int p, int l, int r)
{
    l(p) = l; r(p) = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);       
}

void spread(int p)
{
    if (mark(p))
    {
        int mark = mark(p);
        mx(2 * p) = max(mark, mx(2 * p));
        mx(2 * p + 1) = max(mark, mx(2 * p + 1));
        mark(2 * p) = max(mark, mark(2 * p));
        mark(2 * p + 1) = max(mark, mark(2 * p + 1));
        mark(p) = 0;
    }
}

void update(int p, int l, int r, int val)
{
    if (l <= l(p) && r >= r(p))
    {
        mx(p) = max(mx(p), val);
        mark(p) = max(mark(p), val);
        return;
    }
    spread(p);  // 下传延迟标记
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid)
        update(2 * p, l, r, val);
    if (r > mid)
        update(2 * p + 1, l, r, val);
    mx(p) = max(mx(2 * p), mx(2 * p + 1));
}

int ask(int p, int l, int r)
{
    if (l <= l(p) && r >= r(p)) return mx(p);
    spread(p);
    int mid = (l(p) + r(p)) >> 1;
    int lmx = 0, rmx = 0;
    if (l <= mid)
        lmx = ask(2 * p, l, r);
    if (r > mid)
        rmx = ask(2 * p + 1, l, r);
    return max(lmx, rmx);
}

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vi res;
        // 离散化
        vi nums;
        for (auto &p : positions)
        {
            nums.push_back(p[0]);
            nums.push_back(p[0] + p[1] - 1);
        }
        int n = nums.size();

        auto raw = nums;
        sort(raw.begin(), raw.end());
        vi val(n);
        REP(i, 0, n - 1)
        {
            val[i] = upper_bound(raw.begin(), raw.end(), nums[i]) - raw.begin();
        }

        memset(tree, 0, sizeof tree);
        build(1, 1, SIZE);

        for (int i = 0; i < n; i += 2)
        {
            int l = val[i], r = val[i + 1];
            update(1, l, r, ask(1, l, r) + positions[i / 2][1]);
            res.push_back(ask(1, 1, SIZE));
        }
        return res;
    }
};