#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 求2~n中每个数i在1~i中与其互质的数的个数
// eratosthenes筛法+欧拉函数
vector<int> euler(int n)
{
    vector<int> phi(n + 1);
    for(int i = 2; i <= n; ++i) phi[i] = i;
    for (int i = 2; i <= n; ++i)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] = phi[j] / i  * (i - 1);
    return phi;
}

int main(int argc, char const *argv[])
{
    vector<int> phi = euler(1000);
    for (int i = 3; i < phi.size(); ++i)
    {
        phi[i] += phi[i - 1];
    }
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i)
    {
        int tar;
        cin >> tar;
        cout << i << " " << tar << " " << 3 + 2 * phi[tar] << endl;
    }
    return 0;
}
