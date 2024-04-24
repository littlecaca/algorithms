#include <map>
#include <vector>

using namespace std;


class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) : memory(vector<vector<int>>(n, vector<int>(16))) {
        for (int i = 0; i < n; ++i)
        {
            memory[i][0] = parent[i];
        }
        for (int j = 1; j < 16; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                auto next = memory[i][j - 1];
                if (next == -1) memory[i][j] = - 1;
                else memory[i][j] = memory[next][ j - 1];
            }
        }
    }

    
    int getKthAncestor(int node, int k) {
        if (k == 0)
            return node;
        if (node == -1) return -1;
        int t = 1;
        for (int i = 0; i < 16; ++i, t <<= 1)
        {
            if (k & t)
            {
                return getKthAncestor(memory[node][i], k - t);
            }
        }
        return 0;
        
    }

private:
    vector<vector<int>> memory;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */