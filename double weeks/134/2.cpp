#include <unordered_set>
#include <climits>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int left = 0, right = enemyEnergies.size() - 1;
        ll ans = 0;
        while (left <= right)
        {
            if (currentEnergy >= enemyEnergies[left])
            {
                ans += currentEnergy / enemyEnergies[left];
                currentEnergy = currentEnergy % enemyEnergies[left];
            }
            else
            {
                if (ans >= 1)
                    currentEnergy += enemyEnergies[right--];
                else
                    return 0;
            }
        }
        return ans;
    }
};