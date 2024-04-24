    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <algorithm>

    using namespace std;

    class Solution {
    public:
        vector<int> findOriginalArray(vector<int>& changed) {
            if (changed.size() % 2 != 0) return {};
            vector<int> res;
            int record[100001]{};
            for (auto n : changed)
                ++record[n];

            if ((record[0] & 1) != 0) return {};
            for (int i = 0; i < 100001; ++i)
            {
                int second = record[i];
                if (second > 0)
                {
                    if (i * 2 > 100000) return {};
                    record[i * 2] -= second; 
                    
                    int j = i == 0 ? second / 2 : second;
                    while (j--)
                        res.push_back(i);
                }
                else if (second < 0) return {};
            }
            return res;
        }
    };
