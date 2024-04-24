#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> record;
        for (char c : secret)
        {
            ++record[c];
        }
        for (int i = 0; i != guess.size(); ++i)
        {
            char cur = guess[i];
            if (secret[i] == cur)
            {
                ++bulls;
                if (record[cur])
                    --record[cur];
                else
                    --cows;
            }
            else if (record[cur])
            {
                ++cows;
                --record[cur];
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};