#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  
  int T, x, y, a;
  cin >> T;
  while (T--)
  {
    cin >> x >> y >> a;
    int wait = y - 2 * x;
    if (wait <= 0)
    {
      cout << a * x << endl;
    }
    else
    {
      cout << a / 3 * (x + y) + (a % 3) * x << endl;
    }
  }
  return 0;
}