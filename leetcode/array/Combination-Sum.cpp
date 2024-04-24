#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combine;
        DFS(res, candidates, 0, target, combine);
        return res;
    }   
private:
    void DFS(vector<vector<int>> &res, vector<int> &can, int start, int target, vector<int> &combine)
    {
        for (int i = start; i != can.size(); ++i) 
        {
            int ct = target - can[i];
            combine.push_back(can[i]);

            if (ct == 0)
            {
                res.push_back(combine);
            }
            else if (ct > 0)
            {
                DFS(res, can, i, ct, combine);
            }
            else {
                combine.pop_back();
                return;
            }
            
            combine.pop_back();  
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> s {8,7,4,3};
    Solution().combinationSum(s, 11);
    return 0;
}
