#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>

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

class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        constexpr int mod = 1e9 + 7;
        int n = words.size(), m = target.size();
        int k = words[0].size();
        vvi record(k, vi(26));
        REP(i, 0, k - 1)
            REP(j, 0, n - 1)
                ++record[i][words[j][i] - 'a'];

        vi f1(k + 1), f2(k + 1, 1);

        REP(i, 1, m)
        {
            int tar = target[i - 1] - 'a';
            f1[0] = 0;
            REP(j, 1, k)
            {
                f1[j] = ((ll)f2[j - 1] * record[j - 1][tar] % mod + f1[j - 1]) % mod;
            }
            swap(f1, f2);
        }
        return f2.back();
    }
};
