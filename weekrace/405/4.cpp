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
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        unordered_map<string, int> mp;
        int n = words.size();
        REP(i, 0, n -1)
        {
            auto &word = words[i];
            auto it = mp.find(word);
            if (it == mp.end())
                mp[word] = costs[i];
            else
                it->second = min(it->second, costs[i]);
        }


        int m = target.size();
        vi dp(m + 1, INT_MAX);
        dp[0] = 0;
        REP(i, 1, m)
        {
            for (auto &[word, cost] : mp)
            {
                if (i >= word.size() && dp[i - word.size()] != INT_MAX && target.substr(i - word.size(), word.size()) == word)
                    dp[i] = min(dp[i], dp[i - word.size()] + cost);
            }
        } 
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};