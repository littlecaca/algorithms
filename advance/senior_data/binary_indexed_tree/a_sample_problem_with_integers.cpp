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

// =========================================
//   一个能够进行区间查询和区间增加的树状数组
// 分离包含有多个变量的项，使公式中不同变量之间相互独立的思想非常重要。
// =========================================
class BIT
{
public:
    BIT(size_t n) : C(n + 1), Cback(n + 1), sum(n + 1)
    {
        REP(i, 1, n)
        {
            int num;
            cin >> num;
            sum[i] = sum[i - 1] + num;
        }
    }

    ll query(int x)
    {
        ll ans1 = 0;
        ll ans2 = 0;
        int t = x;
        while (x > 0)
        {
            ans1 += C[x];
            ans2 += Cback[x];
            x -= -x & x;
        }
        return (t + 1) * ans1 - ans2;
    }

    ll query(int x, int y)
    {
        return query(y) - query(x - 1) + sum[y] - sum[x - 1];
    }

    void update(int x, int y, int v)
    {
        addC(x, v);
        addC(y + 1, -v);
        addCback(x, x * v);
        addCback(y + 1, -(y + 1) * v);
    }

    void addC(size_t x, int v)
    {
        while (x < C.size())
        {
            C[x] += v;
            x += -x & x;
        }
    }

    void addCback(size_t x, int v)
    {
        while (x < C.size())
        {
            Cback[x] += v;
            x += -x & x;
        }
    }

private:
    vector<ll> C;
    vector<ll> Cback;
    vector<ll> sum;
};

int main(int argc, char const *argv[])
{
    int N, Q;
    cin >> N >> Q;
    auto bit = BIT(N);
    while (Q--)
    {
        char q;
        int x, y, z;
        cin >> q;
        if (q == 'Q')
        {
            cin >> x >> y;
            cout << bit.query(x, y) << endl;
        }
        else
        {
            cin >> x >> y >> z;
            bit.update(x, y, z);
        }
    }

    return 0;
}
