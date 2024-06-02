//Author:XuHt
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100006, M = 300006;
int n, m, t, fa[N], d[N], f[N][20];
struct P {
	int x, y;
	int z;
	bool k;
	bool operator < (const P &w) const {
		return z < w.z;
	}
} p[M];
int g[N][20];
ll sum, ans = LLONG_MAX;
vector<pair<int, int>> e[N];

int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

void kruskal() {
	sort(p + 1, p + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = get(p[i].x), y = get(p[i].y);
		if (x == y) continue;
		fa[x] = y;
		sum += p[i].z;
		p[i].k = 1;
	}
}

void dfs(int x) {
	for (unsigned int i = 0; i < e[x].size(); i++) {
		int y = e[x][i].first;
		if (d[y]) continue;
		d[y] = d[x] + 1;
		f[y][0] = x;
		int z = e[x][i].second;
		g[y][0] = z;
		for (int j = 1; j <= t; j++) {
			f[y][j] = f[f[y][j-1]][j-1];
			g[y][j] = max(g[y][j-1], g[f[y][j-1]][j-1]);
		}
		dfs(y);
	}
}

inline void lca(int x, int y, int &val1, int &val2) {
	if (d[x] > d[y]) swap(x, y);
	for (int i = t; i >= 0; i--)
		if (d[f[y][i]] >= d[x]) {
			if (val1 < g[y][i]){
				val1 = g[y][i];
			}
			y = f[y][i];
		}
	if (x == y) return;
	for (int i = t; i >= 0; i--)
		if (f[x][i] != f[y][i]) {
			val1 = max(val1, max(g[x][i], g[y][i]));
			x = f[x][i];
			y = f[y][i];
		}
	val1 = max(val1, max(g[x][0], g[y][0]));
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
		p[i].k = 0;
	}
	kruskal();
	for (int i = 1; i <= m; i++)
		if (p[i].k) {
			e[p[i].x].push_back(make_pair(p[i].y, p[i].z));
			e[p[i].y].push_back(make_pair(p[i].x, p[i].z));
		}
	t = log(n) / log(2) + 1;
	d[1] = 1;
	// for (int i = 0; i <= t; i++) g[1][i] = -INF;
	dfs(1);
	for (int i = 1; i <= m; i++)
		if (!p[i].k) {
			int val1 = 0, val2 = 0;
			lca(p[i].x, p[i].y, val1, val2);
			ans = min(ans, sum - val1 + p[i].z);

		}
	cout << ans << endl;
	return 0;
}