#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, q, l, r, k;
    string s;
    cin >> n >> q;
    cin >> s;
    vector<int> ope(n + 1);

    while (q--)
    {
        cin >> l >> r >> k;
        ope[l - 1] = ope[l - 1] + k % 26;
        ope[r] = ope[r] - k % 26;
    }

    int move = 0;
    for (int i = 0; i < n; ++i)
    {
        move = ((move + ope[i]) % 26 + 26) % 26;
        s[i] = (s[i] - 'a' + move) % 26 + 'a';
    }
    cout << s << endl;

    return 0;
}