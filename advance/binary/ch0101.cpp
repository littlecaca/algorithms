#include <iostream>
using namespace std;

typedef long long ll;
// 计算快速幂过程中的a * a操作有时也会溢出，因此需要mutiply
// 计算 x * y % p
ll multiply(ll x, ll y, ll p)
{
    ll ans = 0;
    while (y > 0)
    {
        if (y & 1) ans = (ans + x) % p;
        x = (x + x) % p;
        y >>= 1;
    }
    return ans;
}

// caculate (a ^ b) % p
// 快速幂
ll power(ll a, ll b, ll p)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = multiply(ans, a, p) % p;
        a = multiply(a, a, p) % p;
        b >>= 1;
    }
    return ans;
}

// 求逆元
// 条件 b < p, 且b, p互质 == 计算b^(p-2)
ll inverse(ll b, ll p)
{
    b = b % p;
    ll ans = 1;
    ll exp = p - 2;
    while (exp > 0)
    {
        if (exp & 1) ans = multiply(ans, b, p) % p;
        b = multiply(b, b, p) % p;
        exp >>= 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << power(132, 100, 100000) << endl;
    return 0;
}
