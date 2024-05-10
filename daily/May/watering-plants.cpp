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
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int water = capacity;
        for (int i = 0; i < plants.size(); ++i)
        {
            if (water >= plants[i])
            {
                ++ans;
                water -= plants[i];
            }
            else
            {
                ans += 2 * i + 1;
                water = capacity - plants[i];
            }
        }
        return ans;
    }
};