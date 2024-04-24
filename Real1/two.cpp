// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     // 请在此输入您的代码
//     vector<vector<pair<int, int>>> dp(5, vector<pair<int, int>>(5));
//     dp[4][4].second = 1;
//     dp[4][3].first = 1;
//     dp[4][2].second = 1;
//     dp[4][1].first = 1;
//     dp[4][0].second = 1;

//     for (int i = 3; i >= 0; --i)
//     {
//         for (int j = i; j >= 0; --j)
//         {
//             auto left = dp[i + 1][j], right = dp[i + 1][j + 1];
//             dp[i][j].first = left.first * right.first * 2 + left.first * right.second + left.second * right.first
//                 + left.second * right.second;
//             dp[i][j].second = left.first * right.first + left.first * right.second * 2 + left.second * right.first * 2
//                 + left.second * right.second * 2;
//         }
//     }
//     cout << "(" << dp[3][0].first << "," << dp[3][0].second << ")" << " | ";
//     cout << "(" << dp[3][1].first << "," << dp[3][1].second << ")" << endl;
//     cout << "(" << dp[2][0].first << "," << dp[2][0].second << ")" << endl;

//     return 0;
// }

#include <iostream>
#include <cmath>

#define rep(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int ans = 0;

int a[5][10] = {{0, 1, 0, 1, 0, 1}};

void dfs(int r, int j, int k) // 从左上角开始dfs
{
    if (k == 0)
        a[r][j] = a[r - 1][j] | a[r - 1][j + 1];
    else if (k == 1)
        a[r][j] = a[r - 1][j] & a[r - 1][j + 1];
    else if (k == 2)
        a[r][j] = a[r - 1][j] ^ a[r - 1][j + 1];

    if (r == 4 && j == 0) // 递归出口
    {
        if (a[r][j] == 1)
            ans++;
        return;
    }

    if (r + j == 4) // 当前层的终点，切换到下一行
    {
        r++;
        j = 0;
    }
    else
        j++;

    // 三种状态切换
    rep(s, 0, 3)
        dfs(r, j, s);
}

int main()
{
    rep(k, 0, 3)
        dfs(1, 0, k);

    cout << ans << endl;

    return 0;
}