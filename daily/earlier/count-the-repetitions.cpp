#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<pair<int, int>> recall(s2.size(), pair<int, int> {-1, -1});
        int s1cnt = 0, s2cnt = 0;
        int index = 0;
        while (true)
        {
            ++s1cnt;

            for (auto c : s1)
            {
                if (c == s2[index])
                {
                    if (++index == s2.size())
                    {
                        index = 0;
                        ++s2cnt;
                    }
                }
            }
            if (s1cnt == n1) return s2cnt / n2;

            if (recall[index].first != -1) break;
            recall[index] = {s1cnt, s2cnt};
        }

        int s1recur = s1cnt - recall[index].first;
        int s2recur = s2cnt - recall[index].second;
        int res = (n1 - recall[index].first) / s1recur * s2recur + recall[index].second;

        int remain = (n1 - recall[index].first) % s1recur;
        while (remain--)
        {
            for (auto c : s1)
            {
                if (c == s2[index])
                {
                    if (++index == s2.size())
                    {
                        index = 0;
                        ++res;
                    }
                }
            }
        }
        return res / n2;
    }
};