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

class BIT
{
public:
    BIT(int n) : C(n + 1, 1) {
        REP(i, 1, n)
        {
            int father = i + (-i & i);
            if (father <= n)
                C[father] += C[i];
        }
    }

    int query(int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans += C[x];
            x -= -x & x;
        }
        return ans;
    }

    int query(int x, int y)
    {
        return query(y) - query(x - 1);
    }

    void update(int x, int y)
    {
        while (x < C.size())
        {
            C[x] += y;
            x += -x & x;
        }
    }

    vi C;
};

// =================================
//      树状数组 + 倍增
// 以2的整数次幂为步长，能累加则累加
// =================================
int main(int argc, char const *argv[])
{
    int N; 
    cin >> N;
    vi cows(N);
    REP(i, 1, N - 1)
        cin >> cows[i];
    
    BIT mybit = BIT(N);
    _REP(i, N - 1, 0)
    {
        // 倍增查询
        int ans = 0;
        int k = cows[i] + 1;
        int sum = 0;
        _REP(p, log2(N), 0)
        {
            int index = ans + pow(2, p);
            // 这里不能写成<= k，否则会将k个1之后的0也算进去, 11011001
            //                                                 ^
            //                                                 |
            //                                               这里
            if (index <= N && sum + mybit.C[index] < k)
            {
                ans = index;
                sum += mybit.C[index];
            }
        }
        cows[i] = ans + 1;
        mybit.update(ans + 1, -1);
    }

    REP(i, 0, N - 1)
        cout << cows[i] << endl;

    return 0;
}
