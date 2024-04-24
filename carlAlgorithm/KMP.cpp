#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i != haystack.size(); ++i)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                if (j == needle.size() - 1)
                    return i - needle.size() + 1;
                ++j;
            }
        }
        return -1;
    }

    void getNext(vector<int> &next, const string &needle)
    {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i != needle.size(); ++i)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (needle[i] == needle[j])
            {
                ++j;
            }
            
            next[i] = j;
        }
    }
};