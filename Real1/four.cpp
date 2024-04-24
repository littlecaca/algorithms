#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string temp;
    getline(cin, temp);
    int count = stoi(temp);
    vector<int> dp {1};
    int A = 0;
    while (count--)
    {
        int i;
        cin >> i;
        if (i > dp.size())
        {
            for (int j = dp.size() + 1; j <= i; ++j)
            {
                dp.push_back(j * dp[j - 2]);
            }
        }
        A += dp[i - 1];
    }
    while (dp.back() < A)
    {
        dp.push_back(dp.back() * (dp.size() + 1));
    }
    for (int i = dp.size() - 1; i >= 0; --i)
    {
        if (A % dp[i] == 0)
        {
            cout << i + 1;
            break;
        }
    }
    
    return 0;
}