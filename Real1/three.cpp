#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string temp;
    int count;
    getline(cin, temp);
    count = stoi(temp);
    
    string T, S;
    while (count--)
    {
        getline(cin, T);
        getline(cin, S);
        int res = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] != T[i])
            {
                if (i > 0 && i < S.size() - 1 && S[i] != S[i - 1] && S[i] != S[i + 1])
                {
                    S[i] = T[i];
                    ++res;
                }
                else
                {
                    res = -1;
                    break;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}