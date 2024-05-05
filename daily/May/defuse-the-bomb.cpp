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
typedef long long ll;

#define MOD (int)(1e9 + 7)
template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vi res(code.size());
        if (k == 0)
            return res;
        else
        {
            int left = 0, right = 0;
            int sum = 0;
            while (right < abs(k))
                sum += code[right++];
            while (left <= code.size() - 1)
            {
                if (k > 0)
                    res[(left - 1 + code.size()) % code.size()] = sum;
                else
                    res[right] = sum;
                sum += code[right];
                sum -= code[left++];
                right = (right + 1) % code.size();
            }
            return res;
        }
    }
};