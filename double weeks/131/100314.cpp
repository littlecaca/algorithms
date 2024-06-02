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

struct Node
{
    int l, r;
    ll dat, lmax, rmax;
    bool isEmpty = true;
};

// ostream &operator<<(ostream &os, const Node &node)
// {
//     os << node.l << "-" << node.r << "  " << node.dat << "  (" << node.lmax << ", " << node.rmax << ")" << endl;
//     return os;
// }

class ST
{
public:
    ST(int N) : tree(N * 4), size(N)
    {
        function<void(int, int, int)> build = [&](int p, int l, int r) -> void {
            tree[p].l = l, tree[p].r = r;
            if (l == r) { tree[p].dat = tree[p].lmax = tree[p].rmax = 1; return; }
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);

            pushup(tree[p], tree[2 * p], tree[2 * p + 1]);
        };
        build(1, 1, N);
    }

    void change(int p, int x)
    {
        if (tree[p].l == tree[p].r)
        {
            tree[p].rmax = 0;
            tree[p].isEmpty = false;
            return;
        }
        int mid = (tree[p].l + tree[p].r) / 2;
        if (x <= mid)
            change(2 * p, x);
        else
            change(2 * p + 1, x);

        pushup(tree[p], tree[2 * p], tree[2 * p + 1]);
    }

    Node ask(int p, int l, int r)
    {
        if (l <= tree[p].l && r >= tree[p].r)
        {
            return tree[p];
        }
        int mid = (tree[p].l + tree[p].r) / 2;

        Node cur;
        if (l <= mid && r > mid)
        {
            auto lrs = ask(2 * p, l, r);
            auto rrs = ask(2 * p + 1, l, r);
            pushup(cur, lrs, rrs);
        }
        else
        {
            if (l <= mid) cur = ask(2 * p, l, r);
            else if (r > mid) cur = ask(2 * p + 1, l, r);
        }
        return cur;
    }

    void pushup(Node &tar, const Node &left, const Node &right)
    {
        tar.dat = max({left.dat, right.dat, left.rmax + right.lmax});
        tar.lmax = left.lmax;
        if (left.isEmpty) tar.lmax = left.lmax + right.lmax;
        tar.rmax = right.rmax;
        if (right.isEmpty) tar.rmax = right.rmax + left.rmax;
        tar.isEmpty = left.isEmpty && right.isEmpty;
    }

private:
    vector<Node> tree;
    int size;
};


class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int N = min(5 * (int)1e4, 3 * (int)queries.size());
        ST myst = ST(N);

        vector<bool> res;
        for (auto &que : queries)
        {
            int ope = que[0], x = que[1];
            if (ope == 1)
            {
                myst.change(1, x);
            }
            else
            {
                int sz = que[2];
                int ans = myst.ask(1, 1, x).dat;
                cout << ans << endl;
                if (ans >= sz)
                    res.push_back(true);
                else
                    res.push_back(false);

            }
        }
        return res;
    }
};