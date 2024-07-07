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
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> sta;
        int n = nums.size();
        vi res(n, -1);
        REP(i, 0, n * 2 - 2)
        {
            while (!sta.empty() && nums[sta.top()] < nums[i % n])
            {
                res[sta.top() % n] = nums[i % n];
                sta.pop();
            }
            sta.push(i % n);
        }
        return res;
    }
};