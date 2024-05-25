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

/**
 * 线段树
 * - 保存线段树的数组长度要不小于4N才能保证不会越界。
 * 
*/

#define SIZE 1000

// 线段树的构建
struct SegmentTree
{
    int l, r;
    int dat;
} t[SIZE * 4];  // struct数组存储线段树

int A[SIZE + 1];

void build(int p, int l, int r)
{
    t[p].l = l; t[p].r = r;
    if (l == r) { t[p].dat = A[l]; return; }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    t[p].dat = max(t[2 * p].dat, t[2 * p + 1].dat);
}

// 线段树的单点修改
void change(int p, int x, int v)
{
    // 找到叶节点返回
    if (t[p].l == t[p].r) { t[p].dat = v; return; }

    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid)
        change(2 * p, x, v);
    else
        change(2 * p + 1, x, v);
    t[p].dat = max(t[p * 2].dat, t[p * 2 + 1].dat);
}

// 线段树区间查询
int ask(int p, int l, int r)
{
    // 若查询范围覆盖了当前节点
    if (t[p].l >= l && t[p].r <= r)
        return t[p].dat;
    int mid = (t[p].l + t[p].r) / 2;
    int ans = INT_MIN;
    if (l <= mid)
        ans = ask(2 * p, l, r);
    if (r > mid)
        ans = max(ans, ask(2 * p + 1, l, r));
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    build(1, 1, SIZE);

    change(1, SIZE, 10001);
    
    std::cout << ask(1, 1, SIZE) << endl;

    return 0;
}
