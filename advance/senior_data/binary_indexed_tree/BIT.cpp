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

// =======================================
// 树状数组(Binary Indexed Trees)
// 其基本用途是动态地维护序列的前缀和。
//
// 树状数组的基本操作有两个：
// 一个是查询前缀和(O(logn)),
// 另一个是单点改变元素值(O(logn))。
//
// 通过简单修改，可以编程“区间增加+单点查询”
// =======================================

#define N 100000

// 原始序列
int C[N + 1];

// 初始化序列
void init()
{
    REP(i, 1, N)
        C[i] = i;
    
    REP(i, 1, N)
    {
        auto father = i + (-i & i);
        if (father <= N)
            C[father] += C[i];
    }
}

// 查询序列中第1~x个元素之和
int ask(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += C[x];
        x -= -x & x;    // lowbit
    }
    return ans;
}

// 查询序列中[l, r]号元素之和
int ask(int l, int r)
{
    return ask(r) - ask(l - 1);
}

// 给第x号元素增加y
void add(int x, int y)
{
    while (x <= N)
    {
        C[x] += y;
        x += -x & x;
    }
}


// 查询前缀和
int main(int argc, char const *argv[])
{
    init();
    cout << ask(4) << endl;
    add(2, 100);
    cout << ask(4) << endl;
    cout << ask(N) << endl;
    cout << ask(500, N) << endl;
    return 0;
}
