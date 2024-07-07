#include <string>
#include <unordered_set>
#include <numeric>
#include <stack>
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
    int crackNumber(int ciphertext) {
        auto check = [](const string &s) -> bool {
            if (s[0] == '1')
                return true;
            else if (s[0] == '2')
                return s[1] <= '5';
            return false;            
        };

        int dp[2] = {1, 1};
        string s = to_string(ciphertext);
        int n = s.size();
    
        REP(i, 1, n - 1)
        {
            int t = dp[1];
            if (check(s.substr(i - 1, 2)))
                t += dp[0];
            dp[0] = dp[1];
            dp[1] = t;
        }
        return dp[1];
    }   
};