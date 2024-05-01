#include <stack>
#include <queue>
#include <vector>

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
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        while (mainTank >= 5)
        {
            res += 50;
            if (additionalTank > 0)
            {
                ++mainTank;
                --additionalTank;
            }
            mainTank -= 5;
        }
        return res + mainTank * 10;
    }
};