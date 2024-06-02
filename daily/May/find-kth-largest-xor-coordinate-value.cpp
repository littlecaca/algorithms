#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <numeric>
#include <iostream>
#include <climits>
#include <forward_list>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

# define REP(i,a,b) for(int i = a; i <= b; ++i)
# define _REP(i,a,b) for(int i = a; i >= b; --i)
# define DEBUG(num) cout << "debug: " << num << endl;

template <typename T>
bool chmin(T &a, const T &b)
{
	if (a <= b) return false;
	a = b;
	return true;
}

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int, vi, greater<int>> que;
        REP(i, 0, m - 1)
        {
            int row = 0;
            REP(j, 0, n - 1)
            {
                auto tar = row = row ^ matrix[i][j];
                if (i > 0) tar ^= matrix[i - 1][j];
                matrix[i][j] = tar;
                if (que.size() >= k)
                {
                    if (tar > que.top())
                    {
                        que.pop();
                        que.push(tar);
                    }
                }
                else que.push(tar);

            }
        }
        return que.top();
    }
};