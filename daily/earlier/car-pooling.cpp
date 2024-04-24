#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> from, to;
        for (auto &trip : trips)
        {
            ++from[trip[1]];
            ++to[trip[2]];
        }
        int east = 0;
        
        while (capacity >= 0 && !to.empty())
        {
            auto f = from.find(east);
            auto t = to.find(east);
            if (f != from.end())
            {
                capacity -= f->second;
            }
            if (t != to.end())
            {
                to.erase(t);
                capacity += t->second;
            }
            ++east;
        }
        if (to.empty())
            return true;
        return false;
    }
};