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
    bool isValid(string s) {
        stack<char> sta;
        const static string left = "([{";
        const static string right = ")]}";
        for (auto ch : s)
        {
            if (left.find(ch) != string::npos)
            {
                sta.push(ch);
            }
            else
            {
                int index = right.find(ch);
                if (sta.empty() || sta.top() != left[index])
                    return false;
                sta.pop();
            }
        }
        if (!sta.empty())
            return false;
        return true;
    }
};