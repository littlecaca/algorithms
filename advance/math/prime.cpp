#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

// 试除法：确定一个数是否为质数
bool is_prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// 标记质数 Eratosthenes法 O(N loglogN) 非常接近线性了
// 每个合数会被其所有质因子都筛查一次
#define N 10001
vector<bool> mark(N, true);

void primes(vector<bool> &mark)
{
    for (int x = 2; x < mark.size(); ++x)
    {
        if (mark[x]) continue;
        // 性质：小于x**2的x的倍数在扫描更小的数时已经被标记过了
        for (int y = x * x; y < mark.size(); y += x)
        {
            mark[y] = false;
        }
    }
}

// 线性筛查法   O(N)
// 每个合数只会被其最小质因子筛查一次
void linear_primes(int n)
{   
    vector<int> primes(n + 1);
    vector<int> v(n + 1);   // 需要额外的数组记录每个数的最小质因子
    int m = 0;
    for (int i = 2; i < v.size(); ++i)
    {
        if (v[i] == 0)
        {
            v[i] = i;
            primes[m++] = i;
        }
        // 给当前数乘上一个质因子
        for (int j = 0; j < m && primes[j] <= v[i] && primes[j] * i < v.size(); ++j)
        {   
            v[primes[j] * i] = primes[j];
        }
    }

    for (int i = 0; i < m; ++i) cout << primes[i] << " ";
    cout << endl;
}

// 试除法做质因子分解
void divide(int n)
{
    vector<int> primes;
    vector<int> count;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) // i必定为质数
        {
            primes.push_back(i);
            count.push_back(0);
            while (n % i == 0)
            {
                ++count.back();
                n /= i;
            }
        }
    }

    if (n > 1)  // 考虑剩下的因子n是质数的情况
    {
        primes.push_back(n);
        count.push_back(1);
    }
    for (int i = 0; i < primes.size(); ++i)
    {
        cout << primes[i] << " x " << count[i] << "\n";
    }
    cout << flush;
}

// 欧拉函数求1~N中与N互质的数的个数
int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ans = ans * (i - 1) / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1)
        ans = ans * (n - 1) / n;
    return ans;
}

int main(int argc, char const *argv[])
{
    // primes(mark);
    // for (int i = 1; i < mark.size(); ++i)
    // {
    //     if (mark[i]) cout << i << " ";
    // }
    // cout << endl;

    
    // linear_primes(10000);

    // divide(1232);

    cout << phi(7) << endl;
    return 0;
}

