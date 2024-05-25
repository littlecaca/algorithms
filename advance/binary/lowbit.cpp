#include <iostream>
#include <vector>

using namespace std;

constexpr int lowbit(int x)
{
    return x & -x;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    // 建立2**k到k的映射，0 <= k <= 35, 性质：2**k % 37 = 1..36 不重复
    // 简记：2的0-35次方%37的值在1-36之间，没有重合
    int H[37];
    for (int k = 0; k < 36; ++k)
    {
        H[(1ll << k) % 37] = k;
    }

    while (n > 0)
    {
        int low = lowbit(n);
        cout << H[low % 37] << endl;
        n -= low;
    }
    return 0;
}
