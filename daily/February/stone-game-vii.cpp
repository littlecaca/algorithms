#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        auto left = stones.begin(), right = --stones.end();
        int count = 0;
        int i = 0;
        while (left < right)
        {
            int m = min(*(left + 1), *right);
            int n = min(*(left), *(right - 1));
            int j;
            if (m > n)
                j = *left++;
            else
                j = *right--;
            
            if (i++ % 2 != 0) count += j;
        }

        if (i % 2 != 0) count += *left;
        return count;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> exa {1,1,1,7,1,1,1};
    Solution().stoneGameVII(exa);
    return 0;
}
