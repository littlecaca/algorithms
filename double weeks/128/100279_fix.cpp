#include <vector>
#include <string>
#include <queue>


using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<pdd> vpdd;
typedef vector<vd> vvd;
#define yn(ans) printf("%s\n", (ans)?"Yes":"No");
#define YN(ans) printf("%s\n", (ans)?"YES":"NO");
template<class T> bool chmax(T &a, T b) {
	if (a >= b) return false;
	a = b; return true;
}
template<class T> bool chmin(T &a, T b) {
	if (a <= b) return false;
	a = b; return true;
}
#define FOR(i, s, e, t) for ((i) = (s); (i) < (e); (i) += (t)) 
#define REP(i, e) for (int i = 0; i < (e); ++i) 
#define REP1(i, s, e) for (int i = (s); i < (e); ++i)
#define RREP(i, e) for (int i = (e); i >= 0; --i)
#define RREP1(i, e, s) for (int i = (e); i >= (s); --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define maxe max_element
#define mine min_element
ll inf = 1e18;
#define DEBUG printf("%d\n", __LINE__); fflush(stdout);
template<class T> void print(vector<T> &v, bool withSize = false) {
	if (withSize) cout << v.size() << endl;
	REP(i, v.size()) cout << v[i] << " "; 
	cout << endl;
}

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        int N = n;
        vvvi g(N);
        REP(i, edges.size()) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            g[u].pb({v, w});
            g[v].pb({u, w});
        }
        
        vi dis(N, 1e9);
        dis[0] = 0;
        priority_queue<pii, vpii, greater<pii>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first, u = p.second;
            if (d > dis[u]) continue;
            for (auto &next: g[u]) {
                int v = next[0], w = next[1];
                int nd = d + w;
                if (nd < disappear[v] && chmin(dis[v], nd)) pq.push({nd, v});
            }
        }
        REP(i, N) if (dis[i] >= disappear[i]) dis[i] = -1;
        return dis;
    }
};