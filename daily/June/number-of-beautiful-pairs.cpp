#include <map>
#include <climits>
#include <functional>
#include <iomanip>
#include <sstream>
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


class Solution {
public:
    int gcd(int x, int y)
    {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    int countBeautifulPairs(vector<int>& nums) {
        int record[10] = {};
        int ans = 0;
        for (auto n : nums)
        {
            int tail = n % 10;
            REP(i, 1, 9)
            {
                if (gcd(i, tail) == 1)
                    ans += record[i];
            }
            while (n / 10 > 0)
                n /= 10;
            ++record[n];
        }
        return ans;
    }
};