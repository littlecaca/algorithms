#include <iostream>

using namespace std;

// caculate (a * b) % p
long long mul(long long a, long long b, long long p)
{
    long long res = 0;
    while (b)
    {
        if (b & 1) res = (res + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    cout << mul(200, 200, 44) << endl;
    return 0;
}
