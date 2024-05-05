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
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int ans = 0;
        int cur = 0;
        unordered_map<string, int> record;
        int mx = 0;
        while (cur < word.size())
        {
            mx = max(++record[word.substr(cur, k)], mx);
            cur += k;
        }
   
        return word.size() / k - mx;
    }
};