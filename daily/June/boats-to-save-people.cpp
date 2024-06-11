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
    int numRescueBoats(vector<int>& people, int limit) {
        /**
         * 贪心算法
         */
        sort(people.begin(), people.end());
        int dual = 0;
        int left = 0, right = 0;
        while (right < people.size() && people[left] + people[right] <= limit)
            ++right;
        --right;
        while (left < right)
        {
            if (people[left] + people[right] <= limit)
            {
                ++dual;
                ++left;
                --right;
            }
            else
                --right;
        }
        return people.size() - dual;
    }
};