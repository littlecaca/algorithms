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
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        // 离散化
        auto t = nums;
        vi val(n);
        sort(t.begin(), t.end(), greater<int>());
        REP(i, 0, n - 1)
            val[i] = upper_bound(t.begin(), t.end(), nums[i], [](int b, int a) -> bool {
                return b > a;
            }) - t.begin();
        
        vi arr1, arr2;
        vi C1(n + 1), C2(n + 1);
        update(C1, val[0], 1);
        update(C2, val[1], 1);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        REP(i, 2, n - 1)
        {
            int r1 = query(C1, val[i] - 1), r2 = query(C2, val[i] - 1);
            if (r1 > r2 || (r1 == r2 && arr1.size() <= arr2.size()))
            {
                arr1.push_back(nums[i]);
                update(C1, val[i], 1);
            }
            else
            {
                arr2.push_back(nums[i]);
                update(C2, val[i], 1);
            }
        }
        
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }

    int query(vi &C, int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans += C[x];
            x -= -x & x;
        }
        return ans;
    }

    void update(vi &C, int x, int d)
    {
        while (x < C.size())
        {
            C[x] += d;
            x += -x & x;
        }
    }
};