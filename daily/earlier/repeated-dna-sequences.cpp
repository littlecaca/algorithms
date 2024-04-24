#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int, int> records;
        unordered_map<char, int> m
        {
            {'A', 0},
            {'C', 1},
            {'G', 2},
            {'T', 3}
        };
        if (s.size() <= 10) return res;

        int cur = 0;
        for (int i = 0; i != 10; ++i)
        {
            cur = (cur << 2) | m[s[i]];
        }

        ++records[cur];

        for (int i = 10; i != s.size(); ++i)
        {   
            cur = (cur << 2) | m[s[i]];
            cur &= ((1 << 20) - 1);
            if (records[cur]++ == 1)
            {
                res.push_back(s.substr(i - 9, 10));
            }
        }
        return res;
    }
};
