#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> record(26, {INT_MAX, INT_MIN});
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (i < record[s[i] - 'a'].first)
                record[s[i] - 'a'].first = i;
            if (i > record[s[i] - 'a'].second)
                record[s[i] - 'a'].second = i;
        }
        vector<int> res;
        sort(record.begin(), record.end());
        for (int i = 0, j = record[i].second; i < record.size(); ++i)
        {
            if (record[i].first == INT_MAX) break;
            if (record[i].first < j)
            {
                j = max(j, record[i].second);
            }
            else if (record[i].first > j)
            {
                res.push_back(record[i].first);
                j = record[i].second;
            }
        }
        res.push_back(s.size());
        for (int i = res.size() - 1; i > 0; --i)
            res[i] -= res[i - 1];
        return res;

    }
};