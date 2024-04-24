#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 试除法求N的正约数集合 O(n**(1/2))
vector<int> approximate(int n)
{
    vector<int> appros;
    int i;
    for (i = 1; i * i < n; ++i)
    {
        if (n % i == 0)
        {
            appros.push_back(i);
            appros.push_back(n / i);
        }
    }
    if (i * i == n)
        appros.push_back(i);
    return appros;
}


// 倍数法求1..n每个数的正约数集合 O(NlogN)
vector<vector<int>> mark(int n)
{
    vector<vector<int>> res(n + 1);
    for (int i = 1; i * i <= n; ++i)
    {
        for (int j = i; j <= n / i; ++j)
        {
            res[i * j].push_back(i);
            if (i != j) res[i * j].push_back(j);
        }
    }
    return res;
}

// 反质数/反素数
// 求不超过n的最大的反素数
// 引理1：1~N中最大的反素数，就是1~N中约数最多的数中最小的一个
// 引理2：1~N中任何数的不同质因子都不会超过10个，且所有质因子的指数总和不超过30（1 <= N <= 2 * 10^9）
// 引理3：1~N中任意一个反质数的质因子是连续的若干个最小的质数，并且指数单调递减
int antiPrime(int n)
{

}


int main(int argc, char const *argv[])
{
    // vector<int> res = approximate(10000);
    // sort(res.begin(), res.end());
    // for (auto r : res)
    //     cout << r << " ";
    // cout << endl;

    auto res = mark(100);
    for (int i = 1; i < res.size(); ++i)
    {
        sort(res[i].begin(), res[i].end());
        for (auto num : res[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}

