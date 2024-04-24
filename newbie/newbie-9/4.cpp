#include <vector>
#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    vector<int> bits(32);

    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        for (int i = 0; i < 32; ++i)
        {
            if (t & (1 << i))
            {
                ++bits[i];
            }
        }
    }

    long long  res = 0;
    for (int b : bits)
    {
        res += (long long) b * (b - 1) / 2;
    }
    cout << res << endl;
    
    return 0;
}