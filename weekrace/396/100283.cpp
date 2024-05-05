#include <unordered_map>
#include <cstdlib>
#include <set>
#include <string>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    int minAnagramLength(string s) {
        for (int i = 1; i <= s.size() /  2; ++i)
        {
            if (s.size() % i == 0)
            {
                bool flag = true;
                int cur = 0;
                string tar = s.substr(cur, i);
                sort(tar.begin(), tar.end());
                cur += i;
                while (cur < s.size())
                {
                    string temp = s.substr(cur, i);
                    sort(temp.begin(), temp.end());
                    if (temp != tar)
                    {
                        flag = false;
                        break;
                    }
                    cur += i;
                }
                if (flag) return i;
            }
        }
        return s.size();
    }
};