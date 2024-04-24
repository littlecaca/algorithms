#include <vector>
#include <iostream>

using namespace std;

vector<pair<string, int>> ops(100006);

int cal(vector<pair<string, int>> &ops, int bit, int now)
{
    now <<= bit;
    for (auto &p : ops)
    {
        int get = p.second & (1 << bit);
        if (p.first == "OR") now |= get;
        else if (p.first == "AND") now &= get;
        else now ^= get;
    }
    return now;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> ops[i].first >> ops[i].second;
    
    int cur = 0;
    int res = 0;
    for (int bit = 29; bit >= 0; --bit)
    {
        int res0 = cal(ops, bit, 0);
        int res1 = cal(ops, bit, 1);
        if (cur + (1 << bit) <= m && res1 > res0)
        {
            cur += 1 << bit;
            res += res1;
        }
        else
            res += res0;
    }
    cout << res << endl;

    return 0;
}
