#include <vector>

using namespace std;

// 阶乘分解
// 计算n!中各个质因子以及其出现的次数
void resolve(vector<int> &primes, vector<int> &count, int n)
{
    // 首先算2-n中出现的质数，O(n)
    vector<int> v(n + 1);   // v[i]记录i的最小质因数，目的是为了避免重复，达到线性

    for (int i = 2; i <= n; ++i)
    {
        if (v[i] == 0)
        {
            v[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= v[i] && primes[j] * i < v.size(); ++j)
        {
            v[i * primes[j]] = primes[j];
        }
    }

    // 然后计算每个质数p在1..N中出现的次数 O(NlogN)
    for (int i = 0; i < primes.size(); ++i)
    {
        int p = primes[i];
        while (p <= n)
        {
            count[i] += n / p;
            p *= p;
        }
    }
}