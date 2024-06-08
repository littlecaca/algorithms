#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>

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

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vi res(num_people);
        int d = (1 + num_people) * num_people / 2;
        int layer = 0;
        int total = 0;

        // while (total + d <= candies)
        // {
        //     total += d;
        //     d += num_people * num_people;
        //     ++layer;
        // }

        // 这里可以采用公式加快速度
        int p = (int)(sqrt(0.25 + 2 * candies) - 0.5);
        layer = p / num_people;
        total = (layer * num_people + 1) * layer * num_people / 2;


        int sum = ((layer - 1) * num_people + 2) * layer / 2;
        REP(i, 0, num_people - 1)
        {
            res[i] = sum;
            sum += layer;
        }

        int start = layer * num_people + 1;
        int i = 0;
        while (candies > total)
        {
            int t = min(candies - total, start);
            res[i++] += t;
            total += t;
            ++start;
        }
        return res;
    }
};