#include <queue>
#include <vector>
#include <forward_list>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inde(numCourses);
        vector<forward_list<int>> graph(numCourses);
        for (auto &pre : prerequisites)
        {
            ++inde[pre[0]];
            graph[pre[1]].push_front(pre[0]);
        }
        int count = numCourses;
        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inde[i] == 0) que.push(i);
        }

        // 拓扑序列算法
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            --count;

            for (auto next : graph[cur])
            {
                if (--inde[next] == 0)
                {
                    que.push(next);
                }
            }
        }


        if (count > 0) return false;
        return true;
    }
};