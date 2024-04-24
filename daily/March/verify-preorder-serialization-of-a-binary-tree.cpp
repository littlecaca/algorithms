#include <stack>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> record;
        bool flag = false;
        
        for (auto c : preorder)
        {
            if (c == ',')
            {
                flag = false;
                continue;
            }

            if (c == '#')
            {
                while (!record.empty() && record.top() == '#')
                {
                    record.pop();
                    if (record.empty())
                        return false;
                    record.pop();
                }
            
                record.push(c);
            }
            else
            {
                if (!flag)
                {
                    record.push(c);
                    flag = true;
                }
            }
        }
        if (record.size() == 1 && record.top() == '#')
            return true;
        return false;
    }
};