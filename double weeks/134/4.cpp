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
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans = 0;
        vpii record;
        for (auto i : nums)
        {
            for (auto &[a, b] : record)
                a = a & i;
            record.emplace_back(i, 1);
            unordered_map<int, int> mp;
            for (auto [a, b] : record)
                if (a >= k)
                    mp[a] += b;
            ans += mp[k];
            record.clear();
            for (auto [a, b] : mp)
                record.emplace_back(a, b);
        }
        return ans;
    }
};
