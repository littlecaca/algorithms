#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        unordered_map<int, int> records;

        int mask = 0;
        for (int i = 0; i != words.size(); ++i)
        {
            for (auto c : words[i])
            {
                mask |= (1 << (c - 'a'));
            }

            records[mask] = max(records[mask], (int)words[i].size());
            mask = 0;
        }

        for (auto i = records.begin(); i != records.end(); ++i)
        {
            for (auto j = i; j != records.end(); ++j)
            {
                if (((*i).first & (*j).first) == 0)
                {
                    res = max(res, (*i).second * (*j).second);
                }
            }
        }
        return res;
    }
};
