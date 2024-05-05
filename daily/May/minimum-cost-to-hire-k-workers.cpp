#include <climits>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;
        int n = quality.size();
        for (int i = 0; i < n; ++i)
            workers.push_back({(double)wage[i] / quality[i], i});

        sort(workers.begin(), workers.end());

        priority_queue<int> que;
        double res = 0;
        int group = 0;
        for (auto work : workers)
        {
            double wq = work.first, q = quality[work.second];
            if (que.size() < k)
            {
                group += q;
                res = group * wq;
                que.push(q);
            }
            else if (q < que.top())
            {
                group += q - que.top();
                que.pop();
                que.push(q);
                res = min(res, group * wq);
            }
        }
        return res;
    }   
};