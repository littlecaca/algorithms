#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int m = tomatoSlices, n = cheeseSlices;
        if (m % 2 != 0) return {};
        int x = m / 2 - n;
        int y = 2 * n - m / 2;
        if (x < 0 || y < 0) return {};
        return {x, y};
    }
};