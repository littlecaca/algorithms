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
 
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        REP(i, 0, n - 1)
        {
            if (nums[i] == 0)
            {
                ++count;
                if (i + 1 < n)
                    nums[i + 1] ^= 1;
                else return -1;
                if (i + 2 < n)
                    nums[i + 2] ^= 1;
                else return -1;
            }
        }
        return count;

    }
};