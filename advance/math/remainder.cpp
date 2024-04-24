#include <iostream>
#include <vector>

using namespace std;

// 余数之和
// 定理：任意x <= i <= int(k / int(k / x)), int(k / i)的值都等int(k / x)
// 计算(k mod 1) + (k mod 2) + ... + （k mod n)
// 时间复杂度 O(k ^ (1/2))，因为i在1..n之间int(k / i)至多有k^(1/2)个不同的值
int remainder_sum(int n, int k)
{
    int ans = n * k;
    for (int i = 1, next; i <= n; i = next + 1)
    {
        next = (k / i)? min(k / (k / i), n) : n;    // 注意不要有除0异常
        ans -= (k / i) * (next - i + 1) * (next + i) / 2;   // 等差数列公式
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << remainder_sum(12, 125012) << endl;
    return 0;
}
