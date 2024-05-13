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
    int countTexts(string pressedKeys) {
        #define MOD ((int)1e9 + 7)
        
        vi dp1((int)1e5 + 1);
        vi dp2((int)1e5 + 1);
        dp1[0] = 1;
        dp2[0] = 1;
        
        for (int i = 1; i < dp1.size(); ++i)
        {
            for (int j = 1; j <= 3; ++j)
            {
                if (i >= j)
                {
                    dp1[i] = (dp1[i] + dp1[i - j]) % MOD;
                    dp2[i] = (dp2[i] + dp2[i - j]) % MOD;
                }
            }
            if (i >= 4)
                dp2[i] = (dp2[i] + dp2[i - 4]) % MOD;
        }

        ll ans = 1;

        char last = pressedKeys[0];
        int count = 0;
        for (auto ch : pressedKeys)
        {
            if (ch == last)
                ++count;
            else
            {
                if (last == '7' || last == '9')
                    ans = (ans * dp2[count]) % MOD;
                else
                    ans = (ans * dp1[count]) % MOD;
                last = ch;
                count = 1;
            }
        }
        if (last == '7' || last == '9')
            ans = (ans * dp2[count]) % MOD;
        else
            ans = (ans * dp1[count]) % MOD;
        return ans;
    }   
};