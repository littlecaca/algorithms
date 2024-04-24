#include <map>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// int gcd(int x, int y)
// {
//     int t = x % y;
//     while (t != 0)
//     {
//         x = y;
//         y = t;
//         t = x % y;
//     }
//     return y;
// }

// int main()
// {
//     // 请在此输入您的代码
//     int count;
//     cin >> count;
//     vector<int> nums(count);
//     auto it = nums.begin();
//     while (count--)
//     {
//         cin >> *it++;
//     }
//     // cout << nums[0] << " " << nums[1] << endl;
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         for (int j = i + 1; j < nums.size(); ++j)
//         {
//             if (gcd(nums[i], nums[j]) > 1)
//             {
//                 cout << i + 1 << " " << j + 1 << endl;
//                 goto end;
//             }
//         }
//     }
//     end:
//     return 0;
// }

// 分解质因子
int resolve_factor(int x, int idx, map<int, int> &factors)
{
    int pos = INT_MAX;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i) continue;    // 不能整除，跳过
        while (x % i == 0)      // i是质因子
        {
            x /= i;
            auto res = factors.find(i);
            if (res != factors.end())   // i是之前数的因子
            {
                pos = min(pos, res->second);
            }
            else
                factors.insert({i, idx});
        }
    }
    // 还要考虑剩余的x
    auto res = factors.find(x);
    if (res != factors.end())
    {
        pos = min(pos, res->second);
    }
    else
        factors.insert({x, idx});
    
    return pos;
}


int main()
{
    int count;
    map<int, int> factors;
    cin >> count;
    int pos = INT_MAX;
    int res = -1;
    for (int i = 1; i <= count; ++i)
    {
        int x;
        cin >> x;
        int t = resolve_factor(x, i, factors);
        if (pos > t)
        {
            pos = t;
            res = i;
        }
    }
    cout << pos << " " << res;

    return 0;
}