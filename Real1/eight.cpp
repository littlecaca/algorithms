#include <vector>
#include <iostream>

using namespace std;


int main()
{
    long long lines, n, m, k;
    cin >> lines;
    while (lines--)
    {
        cin >> n >> m >> k;
        long long l = (k - 1) * m + 2;
        long long r = k * m + 1;
        long long ans = 1;
        while (r <= n)
        {
            ans += r - l + 1;
            l = (l - 1) * m + 2;
            r = r * m + 1;
        }
        ans += max(0LL, n - l + 1);
        cout << ans << endl;
    }

    return 0;
}