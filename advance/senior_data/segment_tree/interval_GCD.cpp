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

ll gcd(ll x, ll y)
{
    while (y != 0)
    {
        ll temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

struct Node
{
    int l, r;
    ll gcd;
};

/**
 * 线段树
*/
class ST
{
public:
    ST(const vector<ll> &A, int N) : t(N * 4), count(N) 
    {
        function<void(int, int, int)> build = [&](int p, int l, int r) -> void {
            t[p].l = l; t[p].r = r;
            if (l == r) { t[p].gcd = A[l] - A[l - 1]; return; }

            int mid = (l + r) >> 1;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);

            pushup(t[p], t[2 * p], t[2 * p + 1]);
        };
        build(1, 1, N);
    }

    void update(int p, int l, int r, ll d)
    {
        update(1, l, d);
        /**
         * 这里需要注意特判r==N
        */
        if (r + 1 <= count)
            update(1, r + 1, -d);
    }

    void update(int p, int x, ll d)
    {
        if (t[p].l == t[p].r) { t[p].gcd += d; return; }
        int mid = (t[p].l + t[p].r) >> 1;
        if (x <= mid)
            update(2 * p, x, d);
        else
            update(2 * p + 1, x, d);

        pushup(t[p], t[2 * p], t[2 * p + 1]);
    }

    ll query(int p, int l, int r)
    {
        if (l <= t[p].l && r >= t[p].r)
            return abs(t[p].gcd);
        int mid = (t[p].l + t[p].r) >> 1;
        ll val = 0;
        if (l <= mid) val = gcd(val, query(p * 2, l, r));
	    if (r > mid) val = gcd(val, query(p * 2 + 1, l, r));
        return abs(val);
    }

private:
    void pushup(Node &tar, const Node &left, const Node &right)
    {
        tar.gcd = gcd(left.gcd, right.gcd);
    }
    vector<Node> t;
    int count;
};

/**
 * 树状数组
*/
class BIT
{
public:
    BIT(int N) : C(N + 1), count(N) {}
    
    void update(int l, int r, ll v)
    {
        update(l, v);
        update(r + 1, -v);
    }

    void update(int x, ll v)
    {
        while (x <= count)
        {
            C[x] += v;
            x += -x & x;
        }
    }

    ll query(int x)
    {
        ll ans = 0;
        while (x > 0)
        {
            ans += C[x];
            x -= -x & x;
        }
        return ans;
    }
private:
    vector<ll> C;
    int count;
};

/**
 * 本题主要利用求最大公约数的“更相减损术”，即gcd(x, y) = gcd(x, x-y)，因此
 * 可以把原数组转化为其“差分序列”来求最大公约数，这样就可以进行区间增加（而不局限于单点增加）。
 * 另外还需要用树状数组来求第一个原始值x。
*/

/**
 * 这道题让我自闭了。
 * 就因为C l r d 的这个d并没有规定是int，还可能使ll呢。我默认它是int了，而且
 * 后续发现之后仅仅修改了初始保存它的变量类型，一直忘记函数的参数类型没有跟着改。
 * 我。。。。气死了。。。。。妈的。。。。。啊啊啊啊啊啊啊啊啊啊 
*/
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    /* code */
    int N, M;
    cin >> N >> M;
    vector<ll> A(N + 1);
    REP(i, 1, N)
        cin >> A[i];
    ST myst = ST(A, N);
    BIT mybit = BIT(N);

    while (M--)
    {
        char mark;
        int x, y;
        ll z;
        cin >> mark;
        if (mark == 'Q')
        {
            cin >> x >> y;
            ll val = x < y ? myst.query(1, x + 1, y) : 0;
            cout << gcd(mybit.query(x) + A[x], val) << endl;
        }
        else
        {
            cin >> x >> y >> z;
            myst.update(1, x, y, z);
            mybit.update(x, y, z);
        }
    }
    return 0;
}
