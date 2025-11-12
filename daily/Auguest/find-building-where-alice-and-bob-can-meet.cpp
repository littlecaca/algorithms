#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct Node
    {
        int index;
        int height;
        int seq;
    };

    friend bool operator<(const Node &lhs, const Node &rhs)
    {
        return lhs.index < rhs.index;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n, -1);

        vector<Node> record;
        for (int i = 0; i < n; ++i)
        {
            auto &q = queries[i];
            int left = q[0], right = q[1];
            if (left > right) swap(left, right);
            if (left == right || heights[left] < heights[right])
                res[i] = right;
            else
                record.push_back({right, heights[left], i});
        }

        vector<int> sta;
        sort(record.begin(), record.end());
        int cur = record.size() - 1;
        int m = heights.size();
        for (int i = m - 1; i >= 0; --i)
        {
            while (cur >= 0 && i == record[cur].index)
            {
                auto it = upper_bound(sta.rbegin(), sta.rend(), record[cur].height, [&](const int &b, const int &a) -> bool {
                    return b < heights[a];
                });
                if (it != sta.rend())
                {
                    res[record[cur].seq] = *it;
                }
                --cur;
            }

            while (!sta.empty() && heights[i] >= heights[sta.back()])
            {
                sta.pop_back();
            }
            sta.push_back(i);
        }

        return res;
    }
};
