
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
    bool isPalindrome(const string &s)
    {
        int left = 0, right = s.size() - 1;
        while (left <= right)
        {
            if (s[left] != s[right])
                return false;
            ++left; --right;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> trace;
        function<void(int)> backTracking = [&](int cur) -> void {
            if (cur >= s.size())
            {
                res.push_back(trace);
                return;
            }
            for (int i = cur; i < s.size(); ++i)
            {
                if (isPalindrome(s.substr(cur, i - cur + 1)))
                {
                    trace.push_back(s.substr(cur, i - cur + 1));
                    backTracking(i + 1);
                    trace.pop_back();
                }
            }
        };
        backTracking(0);
        return res;
    }
    
};