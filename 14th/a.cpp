#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int n = 1;
    int count = 0;
    while (n < 100000000)
    // while (n < 10000)
    {
        int bits[8];
        int i;
        int j = n;
        for (i = 0; j != 0; ++i)
        {
            bits[i] = j % 10;
            j /= 10;
        }

        if (i % 2 == 0)
        {
            int t = i / 2;
            int c1 = 0, c2 = 0;
            for (int k = 0; k < t; ++k)
            {
                c1 += bits[k];
                c2 += bits[k + t];
            }
            if (c1 == c2)
            {
                ++count;
                // cout << n << endl;
            }
        }
        ++n;
    }
    cout << count;
    
    return 0;
}
