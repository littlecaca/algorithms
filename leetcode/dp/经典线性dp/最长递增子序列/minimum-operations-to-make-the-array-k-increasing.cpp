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
    int kIncreasing(vector<int>& arr, int k) {
        // 二分 + 贪心
        int ans = 0;
        REP(i, 0, k - 1)
        {
            vi f;
            int count = 0;
            for (int j = i; j < arr.size(); j += k)
            {
                ++count;
                int num = arr[j];
                if (f.empty() || f.back() <= num)
                    f.push_back(num);
                else
                {
                    auto it = upper_bound(f.begin(), f.end(), num);
                    *it = num;
                }
            }
            ans += count - f.size();
        }
        return ans;
    }
};