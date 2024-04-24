#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto com = [] (const pair<int, int> &lhs, const pair<int, int> &rhs) { return lhs.second > rhs.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            decltype(com)> heap(com);
        unordered_map<int, int> record;
        for (auto n : nums)
        {
            ++record[n];
        }
        for (auto &p : record)
        {
            if (heap.size() >= k)
            {
                if (p.second > heap.top().second)
                {
                    heap.pop();
                    heap.push(p);
                }
            }
            else
            {
                heap.push(p);
            }
        }
        vector<int> ans;
        while (!heap.empty())
        {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;

    }
};