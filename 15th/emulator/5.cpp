#include <iostream>
#include <map>

using namespace std;
int main()
{
    // 请在此输入您的代码
    int N, A;
    cin >> N;
    int max_energy = 0;
    map<int, int> threshs;

    while (N--)
    {
        cin >> A;
        for (auto &p : threshs)
        {
            if (A > p.first)
                threshs[A] = max(threshs[A], A + p.second);
            else break;
        }
        threshs[A] = max(threshs[A], A);
    }

    for (auto &p : threshs)
        max_energy = max(max_energy, p.second);
    cout << max_energy << endl;

    return 0;
}