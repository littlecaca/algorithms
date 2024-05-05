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
    vector<string> letterCombinations(string digits) {
        const static vector<string> keyboard = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> res;
        string trace;
        if (digits.empty()) return res;
        function<void(int)> backTracking = [&](int cur) -> void {
            if (cur == digits.size())
            {
                res.push_back(trace);
                return;
            }
            
            auto &tar = keyboard[digits[cur] - '2'];
            for (auto ch : tar)
            {
                trace.push_back(ch);
                backTracking(cur + 1);
                trace.pop_back();
            }
        };
        backTracking(0);
        return res;
    }
};