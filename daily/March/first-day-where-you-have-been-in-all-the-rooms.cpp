#include <vector>

using namespace std;

#define MOD (int)(1e9 + 7)

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        // 动态规划加前缀和
        vector<int> record(nextVisit.size() + 1);
        int remain = nextVisit.size();

        for (int i = 0; i < nextVisit.size() - 1; ++i)
        {
            record[i + 1] = 2;
            int j = nextVisit[i];
            if (j < i)
            {
                record[i + 1] = ((long long)record[i + 1] + record[i] - record[j] + MOD) % MOD;
            }
            record[i + 1] = (record[i + 1] + record[i]) % MOD;
        }
        return record[record.size() - 2];
    }
};