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
    string largestMultipleOfThree(vector<int>& digits) {
        /**
         * Amazing feature of 3
         * 
         */

        sort(digits.begin(), digits.end());

        int n = digits.size();
        vvi record(n + 1, vi(3));
        record[0] = {0, INT_MIN, INT_MIN};

        REP(i, 1, n)
        {
            int d = digits[i - 1];
            int cur = d % 3;

            REP(j, 0, 2)
            {
                record[i][j] = max(record[i - 1][j], record[i - 1][(j - cur + 3) % 3] + 1);
            }
        }

        // cout << record[n][0] << endl;
        string ans;

        int now = 0;
        _REP(i, n, 1)
        {
            int d = digits[i - 1];
            int cur = d % 3;
            int tar = (now - cur + 3) % 3;
            if (record[i - 1][tar] + 1 == record[i][now])
            {
                ans.push_back(d + '0');
                now = tar;
            }
        }

        if (ans.find_first_not_of('0') == string::npos && !ans.empty())
            return "0";
        return ans;
    }
};