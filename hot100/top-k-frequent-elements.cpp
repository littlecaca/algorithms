#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>

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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for (int n : nums)
            ++record[n];

        auto compare = [&record](int a, int b) { return record[a] > record[b]; };
        priority_queue<int, vector<int>, decltype(compare)> que(compare);

        for (auto &p : record)
        {
            if (que.size() < k)
                que.push(p.first);
            else
            {
                if (p.second > record[que.top()])
                {
                    que.pop();
                    que.push(p.first);
                }
            }
        }
        vector<int> res;
        while (!que.empty())
        {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};