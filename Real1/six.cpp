#include <vector>
#include <iostream>
using namespace std;

#define MOD  998244353      // 把MOD声明为预编译符号或者静态常量可以很大提高性能
int dp[2][10][10][10][10];
int m, n;

int main()
{
    // 请在此输入您的代码
    cin >> n >> m;

    // 初始化
    for (int a = 0; a < 10; a += 2)
        for (int b = 1; b < 10; b += 2)
            for (int c = 0; c < 10; c += 2)
                for (int d = 1; d < 10; d += 2)
                    dp[1][a][b][c][d] = 1;
    
    // 迭代
    for (int i = 5; i <= n; ++i)
    {
        int p = i % 2;
        for (int a = p; a < 10; a += 2)
            for(int b = 1 - p; b < 10; b += 2)
                for (int c = p; c < 10; c += 2)
                    for (int d = 1 - p; d < 10; d += 2)
                    {
                        int res = 0;
                        auto &temp = dp[i % 2][b][c][d];
                        for (int k = p; k < 10; k += 2)
                            if (a + b + c + d + k <= m)
                                res = (res  + temp[k]) % MOD;
                        dp[1 - p][a][b][c][d] = res;
                    }
    }

    // 得出结果
    int ans = 0;
    int p = n % 2;
    for (int a = p; a < 10; a += 2)
        for(int b = 1 - p; b < 10; b += 2)
            for (int c = p; c < 10; c += 2)
                for (int d = 1 - p; d < 10; d += 2)
                {
                    ans = (ans + dp[1 - p][a][b][c][d]) % MOD;
                }
    cout << ans << endl;
    
    return 0;
}