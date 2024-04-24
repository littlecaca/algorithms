#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> record;
        auto left = s.begin(),
             right = left;
        int res = 0;
        int cur = 0;
        while (right != s.end())
        {
            if (record.count(*right))
            {
                while (*left != *right)
                {
                    record.erase(*left);
                    --cur;
                    ++left;
                }
                ++left;
            }
            else
            {
                record.insert(*right);
                res = max(res, ++cur);
            }
            ++right;
        }
        return res;
    }
};