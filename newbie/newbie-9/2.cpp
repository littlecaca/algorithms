#include <algorithm>
#include <vector>
#include <string>

#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> graph(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> graph[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += count(graph[i].begin(), graph[i].end(), '1');
    int x = cnt - 2 * k;
    int y = k - x;
    cout << x << " " << y << endl;

    return 0;
}