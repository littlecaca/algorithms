#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        for (int i = left; i <= right; ++i)
        {
            string &w = words[i];
            if (vowels.count(w.front())
                && vowels.count(w.back()))
                ++count;
        }
        return count;
    }
};