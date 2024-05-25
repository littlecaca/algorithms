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

// ==============================
//      归并排序求逆序对数
// ==============================
class Solution {
public:
    int reversePairs(vector<int>& record) {
        // 既可以使用树状数组，也可以使用归并排序，但是本题数据范围未知，还是使用归并排序好一点
        int n = record.size();
        vi back(n);
        int ans = 0;

        // 归并排序
        function<void(int, int)> merge = [&](int l, int r) -> void {
            if (l >= r) return;
            int mid = (l + r) / 2;
            merge(l, mid);
            merge(mid + 1, r);

            int i1 = l, i2 = mid + 1;
            int des = l;
            while (i1 <= mid && i2 <= r)
            {
                if (record[i1] > record[i2])
                {
                    ans += mid - i1 + 1;
                    back[des++] = record[i2++];
                }
                else
                    back[des++] = record[i1++];
            }
            while (i1 <= mid)
                back[des++] = record[i1++];
            while (i2 <= r)
                back[des++] = record[i2++];
            
            REP(i, l, r)
                record[i] = back[i];
        };

        merge(0, n - 1);
        return ans;
    }
};