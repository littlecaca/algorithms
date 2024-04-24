#include <string>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int countPoints(string rings) {
        vector<char> rods(10);
        int count = 0;
        map<char, int> m{
            {'R', 1},
            {'G', 1 << 1},
            {'B', 1 << 2}
        };
        
        for (int i = 0; i < rings.size(); i += 2)
        {
            rods[rings[i + 1] - '0'] |= m[rings[i]];
        }

        for (auto i : rods)
        {
            if (i == 7)
                ++count;
        }
        return count;
    }
};