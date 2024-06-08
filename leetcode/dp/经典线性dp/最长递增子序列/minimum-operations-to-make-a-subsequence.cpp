#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m = target.size(), n = arr.size();

        /**
         * 原来可以用做LIS的方法做LCS，从而将其优化到O(nlogn)
         */

        /**
         * 转换成最长公共子序列的动态规划问题：O(n2)超出时间限制
         */
        // vi f1(n + 1), f2(n + 1);
        
        // REP(i, 1, m)
        // {
        //     int cur = target[i - 1];
        //     REP(j, 1, n)
        //     {
        //         if (cur == arr[j - 1])
        //             f1[j] = f2[j - 1] + 1;
        //         else
        //             f1[j] = max(f1[j - 1], f2[j]);
        //     }
        //     swap(f1, f2);
        // }
        // return target.size() - f2.back();

        /**
         * 树状数组：O(nlogn)， 可以通过
         * 原理：
         * arr[i]在target中的索引只能有0或者1个，当有1个时，假设其为j
         * 子序列arr[0:i]与target的最长公共子序列就是max{arr[k] (0 <= k < i) 在target中的索引小于j时的最长公共子序列} + 1
         * 所以可以用f[i]表示索引值为i的arr中的元素与target的最长公共子序列
         * 利用树状数组，即可快速得到索引值在0——i之间的arr中的元素与target最长工作子序列。
         * 
         */
        unordered_map<int, int> record;
        REP(i, 0, m - 1)
            record[target[i]] = i;
        
        // vi C(m + 1);

        // int ans = 0;
        // for (int i : arr)
        // {
        //     auto it = record.find(i);
        //     if (it != record.end())
        //     {
        //         int tar = it->second;
        //         int old = query(C, tar);
        //         update(C, tar + 1, old + 1);
        //         ans = max(ans, old + 1);
        //     }
        // }
        // return target.size() - ans;

        /**
         * 贪心 + 二分
         */
        vi f;

        int ans = 0;
        for (int i : arr)
        {
            auto it = record.find(i);
            if (it != record.end())
            {
                if (f.empty() || it->second > f.back())
                    f.push_back(it->second);
                else
                {
                    auto it2 = lower_bound(f.begin(), f.end(), it->second);
                    *it2 = it->second;
                }
            }
        }
        return target.size() - f.size();
    }

    // int query(vi &C, int x)
    // {
    //     int ans = 0;
    //     while (x > 0)
    //     {
    //         ans = max(C[x], ans);
    //         x -= -x & x;
    //     }
    //     return ans;
    // }

    // void update(vi &C, int x, int v)
    // {
    //     while (x < C.size())
    //     {
    //         C[x] = max(C[x], v);
    //         x += -x & x;
    //     }
    // }
};