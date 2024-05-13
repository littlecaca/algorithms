#include <bitset>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    int countHousePlacements(int n) {
        #define MOD ((int)1e9 + 7)
        int a = 0, b = 1;
        for (int i = 0; i <= n; ++i)
        {
            auto temp = a;
            a = b;
            b = (a + temp) % MOD;
        }
        return ((long long)b * b) % MOD;
    }
};