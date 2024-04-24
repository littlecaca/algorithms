#include <algorithm>
#include <iterator>
#include <vector>
#include <set>


using namespace std;



class Solution {
public:

    vector<int> dfs(int node, vector<vector<int>> &rgraph, vector<vector<int>> &res)
    {
        vector<int> ancestors;
        for (auto i : rgraph[node])
        {
            auto temp = dfs(i, rgraph, res);
            ancestors.insert(ancestors.end(), 
                make_move_iterator(temp.begin()), make_move_iterator(temp.end()));
        }
        
        sort(ancestors.begin(), ancestors.end());
        auto end = unique(ancestors.begin(), ancestors.end());
        res[node] = vector<int>(ancestors.begin(), end);
        ancestors.push_back(node);
        return ancestors;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> rgraph(n);
        vector<int> in(n);

        for (auto &edge : edges)
        {
            rgraph[edge[1]].push_back(edge[0]);
            ++in[edge[0]];
        }

        for (int i = 0; i < in.size(); ++i)
        {
            if (in[i] == 0)
            {
                dfs(i, rgraph, res);
            }
        }
        return res;
    }
};