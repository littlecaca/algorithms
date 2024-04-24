#include<unordered_set>
#include<iostream>

using namespace std;

unordered_set<int> record;

class Solution {
public:
    int distinctIntegers(int n) {
        int ans = 1;
        for (int i = 1; i < n; ++i)
        {
            if (n % i == 1)
            {
                if (record.find(i) == record.end())
                {
                    record.insert(i);
                    ans += distinctIntegers(i);
                }
            }
        }
        return ans;
    
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().distinctIntegers(3) << endl;
    return 0;
}
