#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 滑动窗口
    string minWindow(string s, string t) {
        // 用map保存t中的各个字符，并记录个数
        unordered_map<char, int> record;
        for (char c : t)
            ++record[c];

        int left = 0, right = 0;
        int count = t.size();
        int res_left = -1;
        int len = INT_MAX;

        // 开始滑动窗口
        while (true)
        {
            // 找到t所有字符
            while (count > 0 && right < s.size())
            {
                if (record.find(s[right]) != record.end())
                {
                    if (record[s[right]] > 0)
                        --count;
                    --record[s[right]];
                }
                ++right;
            }

            if (count > 0)
                break;

            // 尝试收缩窗口
            while (left < right && count <= 0)
            {
                if (record.find(s[left]) != record.end() && ++record[s[left]] > 0)
                {
                    ++count;
                    if (right - left < len)
                    {
                        res_left = left;
                        len = right - left;
                    }
                }
                ++left;
            }
        }
        return res_left == -1 ? "" : s.substr(res_left, len);
    }
};