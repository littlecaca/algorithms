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

/**
 * 线段树
 * - 保存线段树的数组长度要不小于4N才能保证不会越界。
 * - ask函数的返回对象应该是Node，因为必须掌握子节点dat、sum、lmax、rmax信息。
*/

struct Node
{
    int l, r;
    ll dat, lmax, rmax, sum;
};

class ST
{
public:
    ST(const vi &A, int N) : tree(N * 4), size(N)
    {
        function<void(int, int, int)> build = [&](int p, int l, int r) -> void {
            tree[p].l = l, tree[p].r = r;
            if (l == r) { tree[p].sum = tree[p].dat = tree[p].lmax = tree[p].rmax = A[l]; return; }
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);

            pushup(tree[p], tree[2 * p], tree[2 * p + 1]);
        };
        build(1, 1, N);
    }

    void change(int p, int x, int v)
    {
        if (tree[p].l == tree[p].r)
        {
            tree[p].sum = tree[p].dat = tree[p].lmax = tree[p].rmax = v;
            return;
        }
        int mid = (tree[p].l + tree[p].r) / 2;
        if (x <= mid)
            change(2 * p, x, v);
        else
            change(2 * p + 1, x, v);

        pushup(tree[p], tree[2 * p], tree[2 * p + 1]);
    }

    Node ask(int p, int l, int r)
    {
        if (l <= tree[p].l && r >= tree[p].r)
            return tree[p];
        int mid = (tree[p].l + tree[p].r) / 2;

        Node cur;
        if (l <= mid && r > mid)
        {
            /**
             * 这里犯下了一个错误
             * 必须要建立两个临时Node保存，不能让cur代替left，否则在pushup函数中
             * 交叉引用会出现更新错误。
            */
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
        tar.sum = left.sum + right.sum;
        tar.dat = max({left.dat, right.dat, left.rmax + right.lmax});
        tar.lmax = max(left.lmax, left.sum + right.lmax);
        tar.rmax = max(right.rmax, right.sum + left.rmax);
    }

private:
    vector<Node> tree;
    int size;
};


int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;

    vi A(N + 1);
    REP(i, 1, N)
        cin >> A[i];

    ST myst = ST(A, N);

    while (M--)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1)
        {
            if (x > y) swap(x, y);
            cout << myst.ask(1, x, y).dat << endl;
        }
        else
            myst.change(1, x, y);
    }

    return 0;
}
