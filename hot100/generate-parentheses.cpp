#include <stack>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    void explore(vector<string> &res, string &trace, int left, int left_p,  int n)
    {
        if (trace.size() == n * 2)
        {
            res.push_back(trace);
            return;
        }

        if (left > 0)
        {
            trace.push_back('(');
            explore(res, trace, left - 1, left_p + 1, n);
            trace.pop_back();
        }

        if (left_p > 0)
        {
            trace.push_back(')');
            explore(res, trace, left, left_p - 1, n);
            trace.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string trace;
        explore(res, trace, n, 0, n);
        return res;
    }
};