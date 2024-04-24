#include <memory>
#include <vector>

using namespace std;

#define UNREACH 1e8 + 100

class Graph {
public:
    shared_ptr<vector<vector<int>>> gp;

    Graph(int n, vector<vector<int>>& edges) {
        gp.reset(new vector<vector<int>>(n, vector<int>(n, UNREACH)));
        for (auto &e: edges)
            (*gp)[e[0]][e[1]] = e[2];

        for (int i = 0; i < n; ++i)
            (*gp)[i][i] = 0;

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    (*gp)[i][j] = min((*gp)[i][j], (*gp)[i][k] + (*gp)[k][j]); 
    }
    
    void addEdge(vector<int> edge) {
        int n = gp->size();
        int from = edge[0], to = edge[1], cost = edge[2];
        if ((*gp)[from][to] > cost)
        {
            (*gp)[from][to] = cost;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    (*gp)[i][j] = min((*gp)[i][j], (*gp)[i][from] + (*gp)[to][j] + cost); 
            
        }
    }
    
    int shortestPath(int node1, int node2) {
        int ans = gp->at(node1).at(node2);
        return ans == UNREACH ? -1 : ans;
    }
};

