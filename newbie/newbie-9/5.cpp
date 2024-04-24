#include <string>
#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码

    int t, m;
    long long n;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        long long cur = m - 1;
        long long t = m - 1;
        int i = 1;
        while (n > cur)
        {
            ++i;
            t *= m;
            cur += t * i;
        }
        cur -= t * i;
        long long remain = n - cur - 1;
        long long cnt = remain / i;
        string s(i, '0');
        s[0] = '1';
        
        int k = s.size() - 1;
        while (cnt > 0)
        {
            s[k] += cnt % m;
            cnt /= m;
            --k;
        }
        cout << s[remain % i] << endl;
    }
    return 0;
}