#include <map>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> record;

        for (auto c : p)
        {
            ++record[c];
        }

        int count = 0;

        auto left = s.begin(),
             right = left;
             
        vector<int> res;

        while (right != s.end())
        {
            if (record.count(*right) && record.at(*right))
            {
                --record[*right];
                ++count;
            }
            else
            {
                while (*left != *right)
                {
                    ++record[*left];
                    --count;
                    ++left;
                }
                ++left;
            }
            ++right;
            if (count == p.size())
                res.push_back(left - s.begin());
        }
        return res;
    }
};