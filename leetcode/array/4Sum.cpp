#include <algorithm>
#include <array>
#include <map>
#include <vector>

using namespace std;

// 这次用map记录每个数字出现次数，然后将map中的关键字排序，
// 按照顺序遍历,即可排序后的关键字，即可保证不会出现完全相同的结果集
// 但是需要注意的是，由于nums中一个值会出现多次，在结果集中就也可能会出现多次
// ，所以要分析这种情况。

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        map<int, int> m;
        for (auto i : nums)
        {
            ++m[i];
        }
        vector<int> keys;
        for (auto &p : m)
        {
            keys.push_back(p.first);
        }
        sort(keys.begin(), keys.end());

        for (int i = 0; i != keys.size(); ++i)
        {
            if (keys[i] * (long long)4 == target && m[keys[i]] >= 4)
            {
                result.push_back(vector<int>(4, keys[i]));
            }
            for (int j = i + 1; j != keys.size(); ++j)
            {
                if (keys[i] * (long long)3 + keys[j] == target && m[keys[i]] >= 3)
                {
                    result.push_back(vector<int>({keys[i], keys[i], keys[i], keys[j]}));
                }
                if (keys[i] + keys[j] * (long long)3 == target && m[keys[j]] >= 3)
                {
                    result.push_back(vector<int>({keys[j], keys[j], keys[j], keys[i]}));
                }
                if (keys[i] * (long long)2 + keys[j] * (long long)2 == target && m[keys[i]] >= 2 && m[keys[j]] >= 2)
                {
                    result.push_back(vector<int>({keys[j], keys[j], keys[i], keys[i]}));
                }
                for (int k = j + 1; k != keys.size(); ++k)
                {

                    if (keys[i] * (long long)2 + keys[j] + keys[k] == target && m[keys[i]] >= 2)
                    {
                        result.push_back(vector<int>({keys[j], keys[k], keys[i], keys[i]}));
                    }
                    if (keys[j] * (long long)2 + keys[i] + keys[k] == target && m[keys[j]] >= 2)
                    {
                        result.push_back(vector<int>({keys[j], keys[k], keys[j], keys[i]}));
                    }
                    if (keys[k] * (long long)2 + keys[j] + keys[i] == target && m[keys[k]] >= 2)
                    {
                        result.push_back(vector<int>({keys[j], keys[k], keys[k], keys[i]}));
                    }

                    int goal = target - (long long)keys[i] - keys[j] - keys[k];
                    if (goal > keys[k] && m[goal] >= 1)
                    {
                        result.push_back({keys[i], keys[j], keys[k], goal});
                    }
                }
            }
        }

        return result;
    }
};