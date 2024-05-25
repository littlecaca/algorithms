#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <numeric>
#include <iostream>
#include <climits>
#include <forward_list>
#include <functional>

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

# define REP(i,a,b) for(int i = a; i <= b; ++i)
# define _REP(i,a,b) for(int i = a; i >= b; --i)
# define DEBUG(num) cout << "debug: " << num << endl;

template <typename T>
bool chmin(T &a, const T &b)
{
	if (a <= b) return false;
	a = b;
	return true;
}

// ==============================
//       离散化树状数组
// 离散化一个序列的前提是我们只关心这个序列里面元素的相对大小，
// 而不关心绝对大小（即只关心元素在序列中的排名）；离散化的目的是让
// 原来分布零散的值聚集到一起，减少空间浪费。那么如何获得元素排名呢，
// 我们可以对原序列排序后去重，对于每一个 ai
// 通过二分查找的方式计算排名作为离散化之后的值。当然这里也可以不去重，不影响排名。
// ==============================


class BIT
{
public:
    BIT(int n) : C(n + 1) {}

    int query(int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans += C[x];
            x -= -x & x;
        }
        return ans;
    }

    int query(int x, int y)
    {
        return query(y) - query(x - 1);
    }

    void update(int x, int y)
    {
        while (x < C.size())
        {
            C[x] += y;
            x += -x & x;
        }
    }

private:
    vi C;
};

class Solution {
public:
    int reversePairs(vector<int>& record) {
        // 既可以使用树状数组，也可以使用归并排序
        // 本题数据范围未知，使用树状数组的化要进行离散化。
        // 也就是将元素地实际值映射为其相对位置值（即排名）。
        int n = record.size();
        vi temp = record;
        sort(temp.begin(), temp.end());
        auto bit = BIT(n);
        int ans = 0;
        for (auto it = record.rbegin(), end = record.rend(); it != end; ++it)
        {
            int k = lower_bound(temp.begin(), temp.end(), *it) - temp.begin() + 1;
            bit.update(k, 1);
            ans += bit.query(k - 1);
        }
        return ans;
    }
};