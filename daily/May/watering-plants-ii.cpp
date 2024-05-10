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
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int alice = capacityA, bob = capacityB;
        int left = 0, right = plants.size() - 1;
        int ans = 0;
        while (left < right)
        {
            if (alice < plants[left])
            {
                ++ans;
                alice = capacityA;
            }
            alice -= plants[left++];
            if (bob < plants[right])
            {
                ++ans;
                bob - capacityB;
            }
            bob -= plants[right--];
        }
        if (left == right)
        {
            if (max(alice, bob) < plants[left])
                ++ans;
        }
        return ans;
    }
};