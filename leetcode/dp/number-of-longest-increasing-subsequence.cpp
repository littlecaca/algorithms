#include <numeric>
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
    int findNumberOfLIS(vector<int>& nums) {
        vi dp;
        vvi sum;
        vvi buckets;
        dp.push_back(nums[0]);
        sum.push_back({1});
        buckets.push_back({nums[0]});
        
        for (int i = 0; i < nums.size(); ++i)
        {
            auto tar = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (tar == dp.end())
            {
                dp.push_back(nums[i]);
                buckets.push_back({});
                sum.push_back({});
            }
            else
            {
                *tar = nums[i];
            }

            // push the new node into buckets
            int index = tar - dp.begin();
            buckets[index].push_back(nums[i]);
            // find the loc in previous bucket
            int count = 1;
            if (index >= 1)
            {
                auto &b1 = buckets[index - 1];

                // auto pre_tar = upper_bound(b1.begin(), b1.end(), nums[i], greater<>()) - b1.begin();
                // int total = sum[index - 1].back();  // sum[index - 1] will never be empty
                // auto sum_before_loc = pre_tar > 0 ? sum[index - 1][pre_tar - 1] : 0;

                // count = total - sum_before_loc;
            }
            count += sum[index].empty() ? 0 : sum[index].back();
            // sum[index].push_back(count);
        }
        return sum.back().back();


    }
};