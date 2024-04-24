#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
    ll gcd(ll a, ll b)
    {
        while (b != 0)
        {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b)
    {
        return a * b / gcd(a, b);
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll x = coins[0];
        for (int i = 1; i < coins.size(); ++i)
        {
            x = lcm(x, coins[i]);
        }
        
    }
};