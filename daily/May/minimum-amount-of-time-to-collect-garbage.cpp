#include <bitset>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>

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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        vi prefix(garbage.size());
        for (int i = 0; i < travel.size(); ++i)
        {
            prefix[i + 1] = prefix[i] + travel[i];
        }

        int mloc = 0, ploc = 0, gloc = 0;
        for (int i = 0; i < garbage.size(); ++i)
        {
            int m_cnt = 0, p_cnt = 0, g_cnt = 0;
            for (auto c : garbage[i])
            {
                switch (c)
                {
                    case 'M':
                        ++m_cnt;
                        break;
                    case 'P':
                        ++p_cnt;
                        break;
                    case 'G':
                        ++g_cnt;
                        break;
                }
            }

            if (m_cnt > 0)
            {
                ans += prefix[i] - prefix[mloc] + m_cnt;
                mloc = i;
            }
            if (p_cnt > 0)
            {
                ans += prefix[i] - prefix[ploc] + p_cnt;
                ploc = i;
            }
            if (g_cnt > 0)
            {
                ans += prefix[i] - prefix[gloc] + g_cnt;
                gloc = i;

            }
        }
        return ans;
    }
};