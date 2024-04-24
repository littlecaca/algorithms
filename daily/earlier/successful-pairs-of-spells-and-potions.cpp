#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());
        sort(potions.begin(), potions.end());
        for (int i = 0; i != spells.size(); ++i)
        {
            auto edge = lower_bound(potions.begin(), potions.end(), spells[i], 
                [success](int i, int j) { return (long long)i * j < success; });
            res[i] = potions.end() - edge;
        }
        return res;
    }
};