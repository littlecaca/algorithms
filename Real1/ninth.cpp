#include <vector>
#include <iostream>

using namespace std;

#define MOD 998244353

// 求逆元。在mod的意义下，不能直接除一个数，而要乘以它的逆元
int inv(int a)
{
    int p = MOD - 2;
    int ans = 1;
    int t = a % MOD;
    while (p)
    {
        if (p & 1) ans = (long long) ans * t % MOD;
        t = (long long) t * t % MOD;
        p >>= 1;
    }
    return ans;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &A[i]);
    }
    int ans = 0;
    int T = 1, Tpre = 1;
    int prod = 1;
    int m_1 = (m - 1) % MOD;
    m %= MOD;
    for (int i = 1; i <= n; ++i)
    {
        T = (long long)T * (m + i) % MOD * (m - i + 1) % MOD * inv(2 * i) % MOD * inv(2 * i - 1) % MOD;
        Tpre = (long long)Tpre * (m_1 + i) % MOD * (m_1 - i + 1) % MOD * inv(2 * i) % MOD * inv(2 * i - 1) % MOD;
        prod = (long long)prod * A[i] % MOD;
        if (i < n) ans = (ans + (long long) (T - Tpre + MOD) * prod % MOD) % MOD;
        else ans = (ans + (long long) T * prod % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}
