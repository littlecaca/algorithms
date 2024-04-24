#include <algorithm>
#include <vector>
#include <iostream>
// #include <cmath>

using namespace std;

inline long long square_minus(int i, int j) 
{
    return i * i - j * j;
}

inline long long square(int i)
{
    return i * i;
}

inline void find_more(int i, int *lower, int *upper)
{
    *upper = i / 2 + 1;
    *lower = i / 2;
}



int main(int argc, char const *argv[])
{
    int L, R;
    int i = 0;
    int count = 0;
    cin >> L >> R;
    int upper, lower;

    for (int n = L; n <= R; ++n)
    {
        find_more(n, &lower, &upper);

        while (square(start) >= n &&
               (start + start - 1) <= n &&
               square_minus(start, start - 1) <= n) 
        {
            int minus, k = 1;
            bool flag = false;
            while ((minus = square_minus(start, start - k)) <= n)
            {
                if (minus == n)
                {
                    // cout << n << " " << start << " " << start - k << endl;
                    ++count;
                    flag = true;
                    break;
                }
                ++k;
            }
            if (flag) break;
            ++start;
        }
    }
    cout << count;
    return 0;
}
