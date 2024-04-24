#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        multimap<int, int> record;
        for (int i = 0; i < aliceValues.size(); ++i)
        {
            record.insert({aliceValues[i] + bobValues[i], i});
        }
        pair<int, int> result;

        int i = 0;
        for (auto it = record.rbegin(); it != record.rend(); ++it)
        {
            if (i++ % 2 == 0)
                result.first += aliceValues[(*it).second];
            else
                result.second += bobValues[(*it).second];
        }
        
        if (result.first == result.second)
            return 0;
        if (result.first > result.second)
            return 1;
        return -1;
    }
};


