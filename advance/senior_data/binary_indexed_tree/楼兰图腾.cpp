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

    void update(size_t x, int y)
    {
        while (x < C.size())
        {
            C[x] += y;
            x += -x & x;
        }
    }

    void clear()
    {
        fill(C.begin(), C.end(), 0);
    }

private:
    vi C;
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    auto bit = BIT(n);
    vi more(n + 1);
    vi less(n + 1);
    vi nums(n + 1);
    REP(i, 1, n)
        cin >> nums[i];
    REP(i, 1, n)
    {
        more[i] = bit.query(nums[i] + 1, n);
        less[i] = bit.query(nums[i] - 1);
        bit.update(nums[i], 1);
    }

    bit.clear();
    ll ans1 = 0;
    ll ans2 = 0;
    _REP(i, n, 1)
    {
        ans1 += (ll)bit.query(nums[i] + 1, n) * more[i];
        ans2 += (ll)bit.query(nums[i] - 1) * less[i];
        bit.update(nums[i], 1);
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
