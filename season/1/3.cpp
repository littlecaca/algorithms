#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // 请在此输入您的代码
    auto compare = [](const pair<int, int> &a, const pair<int, int> &b)
    { return a.first > a.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
    int T, x, y, a;
    cin >> T;
    while (T--)
    {
        cin >> x >> y >> a;
        int wait = y - 2 * x;
        if (wait <= 0)
        {
            cout << a * x << endl;
        }
        else
        {
            cout << a / 3 * (x + y) + (a % 3) * x << endl;
        }
    }
    return 0;
}