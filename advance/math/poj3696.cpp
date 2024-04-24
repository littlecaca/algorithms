#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

// 求a，b的最大公约数
ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// 快速幂
ll multiply(ll x, ll y,ll p)
{
	ll re=0;
	while(y)
	{
		if(y&1)re=(re+x)%p;
		x=(x+x)%p;y>>=1;
	}
	return re;
}

ll power(ll x, ll y,ll p)
{
	ll re=1;
	while(y)
	{
		if(y&1)re=multiply(re,x,p)%p;
		x=multiply(x,x,p)%p;y>>=1;
	}
	return re;
}

int main(int argc, char const *argv[])
{
    int L;
    ll count = 0;
    while (cin >> L && L!=0)
    {
        ++count;
        ll temp = (ll) 9 * L / gcd(L, 8);

        if (gcd(temp, 10) != 1)
        {
            cout << "Case " << count << ": " << 0 << endl; 
            continue;
        }

        // 欧拉函数求phi(temp) + 试除法求质因子
        ll fai = temp;
        ll n = temp;
        for (ll i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                fai = fai / i * (i - 1);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 1)
            fai = fai / n * (n - 1);

        // 试除法求fai的所有约数 + 快速幂
        for (ll i = 1; i * i <= fai; ++i)
            if (fai % i == 0 && power(10, i, temp) == 1)
            {
                cout << "Case " << count << ": " << i << "\n"; 
                goto end;
            }
        for (ll i = sqrt((double)fai); i >= 1; --i)
            if (fai % i == 0 && power(10, fai / i, temp) == 1)
            {
                cout << "Case " << count << ": " << fai / i << "\n"; 
                goto end;
            }

        end:;
    }
    return 0;
}
