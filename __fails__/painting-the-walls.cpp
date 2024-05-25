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


class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
		#define INF 0x3f3f3f3f
		int n = cost.size();

		/**
		 * 记忆化搜索
		*/
		// vvi dp(n, vi(2 * n + 1, -1));

		// function<int(int, int)> dfs = [&](int i, int k) -> int {
		// 	if (i < k) return 0;
		// 	if (i < 0) return INF;
		// 	if (dp[i][k + n] != -1) return dp[i][k + n];

		// 	dp[i][k + n] = min(dfs(i - 1, k - 1), dfs(i - 1, k + time[i]) + cost[i]);
		// 	return dp[i][k + n];
		// };
		// return dfs(n - 1, 0);

		/**
		 * 动态规划：0-1背包
		*/
		// vvi dp(2, vi(2 * n + 1));
		// int cur = 0, last = 1;
		// REP(i, 0, n - 1)
		// 	dp[last][i] = INF;

		// REP(i, 0, n - 1)
		// {
		// 	REP(j, 0, 2 * n)
		// 	{
		// 		int ans = INF;
		// 		// free
		// 		if (j > 0)
		// 			ans = dp[last][j - 1];
		// 		// paied
		// 		if (j + time[i] < 2 * n + 1)
		// 			chmin(ans, dp[last][j + time[i]] + cost[i]);
		// 		else
		// 			chmin(ans, cost[i]);
		// 		dp[cur][j] = ans;
		// 	}
		// 	swap(cur, last);
		// }
		
		// return dp[last][n];

		
		/**
		 * 动态规划：进行数学优化后的0-1背包
		 * 付费时间之和 >= 免费个数
		 * <=> 	(付费时间 + 1)之和 >= n
		 * 
		 * 物品体积: 付费时间 + 1
		 * 价值：	 费用
		 * 容量：    n
		 * 要从n个物品中选择至少n体积的物品，其费用最低者为最终答案。
		*/

		vi dp(n + 1, INF);
		dp[0] = 0;
		REP(i, 0, n - 1)
		{
			int value = cost[i], t = time[i] + 1;
			_REP(j, n, 1)
				dp[j] = min(dp[j], dp[max(0, j - t)] + value);
		}
		return dp[n];
    }
};


