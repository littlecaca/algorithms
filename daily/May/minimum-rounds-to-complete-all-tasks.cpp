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
    int minimumRounds(vector<int>& tasks) {
        #define INF ((int)1e9 + 100)
        unordered_map<int, int> record;
        for (auto n : tasks)
            ++record[n];

        int ans = 0;
        for (auto [_, v] : record)
        {
            if (v == 1)
                return -1;
            if (v % 3 == 0)
                ans += v / 3;
            else if ((v + 1) % 3 == 0)
                ans += (v - 2) / 3 + 1;
            else 
                ans += (v - 4) / 3 + 2;
        }   
        return ans;
    }
};