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
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int big = -1, little = -1;
        int bigC = 0, littleC = 0;
        int n = nums1.size();

        REP(i, 0, n - 1)
        {
            int a = nums1[i], b = nums2[i];
            int tl = littleC;
            if (a > b) swap(a, b);
            if (a >= big)
                littleC = bigC + 1;
            else if (a >= little)
                littleC = littleC + 1;
            else
                littleC = 1;
            
            if (b >= big)
                bigC = bigC + 1;
            else if (b >= little)
                bigC = tl + 1;
            else    
                bigC = 1;
            
            ans = max(ans, bigC);
            big = b; little = a;
        }
        return ans;
    }
};