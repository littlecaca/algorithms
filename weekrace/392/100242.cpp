#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (auto &c : s)
        {
            int uptoa = 'a' + 26 - c;
            int downtoa = c - 'a';

            if (uptoa < downtoa && uptoa <= k)
            {
                c = 'a';
                k -= uptoa;
            }
            else if (downtoa <= k)
            {
                c = 'a';
                k -= downtoa;
            }
            else
            {
                c = c - k;
                break;
            }
        }
        return s;
    }
};