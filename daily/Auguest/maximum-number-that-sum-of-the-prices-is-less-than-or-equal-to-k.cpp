#include <iostream>

using namespace std;

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        auto count = [](long long num, int bit) -> int {
            return num / (1 << bit);
        };

        
    }
};

int main(int argc, char const *argv[])
{
auto count = [](long long num, int bit) -> long long {
            long long left = num & ((1LL << bit) - 1);
            long long right = (num >> (bit + 1));
            long long ans = right * (1LL << bit);
            if (num & (1LL << bit))
            {
                ans += left + 1;
            }
            return ans;
        };

        auto value = [&count](long long num, int step) -> long long
        {
            long long ans = 0;
            for (int i = step - 1; i < 63; i += step)
            {
                ans += count(num, i);
            }
            return ans;
        };
        cout << value(51, 6) << endl;

    return 0;
}
