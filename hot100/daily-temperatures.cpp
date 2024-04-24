#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mono;
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!mono.empty() && temperatures[i] > temperatures[mono.top()])
            {
                auto tar = mono.top();
                mono.pop();
                res[tar] = i - tar;
            }
            mono.push(i);
        }
        return res;
    }
};