#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> sta;
        string cur;
        string num;
        string ans;
        for (int i = 0; i < s.size(); ++i)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                if (!cur.empty())
                {
                    sta.push(cur);
                    cur.clear();
                }
                while (s[i] != '[')
                    num += s[i++];
                sta.push(num);
                sta.push("[");
                num.clear();
            }
            else if (s[i] == ']')
            {
                string pre;
                while (sta.top() != "[")
                {
                    cur = sta.top() + cur;
                    sta.pop();
                }
                sta.pop();
                int n = stoi(sta.top());
                sta.pop();
                while (n--)
                {
                    pre += cur;
                }
                cur.clear();
                sta.push(pre);
            }
            else
            {
                cur += s[i];
            }

        }
        while (!sta.empty())
        {
            ans = sta.top() + ans;
            sta.pop();
        }
        return ans + cur;
    }
};