#include <iostream>
using namespace std;

int holes[] = {1, 0, 0, 0, 1, 0, 1, 0, 2 , 1};

int count(int num)
{
  int res = 0;
  while (num > 0)
  {
    res += holes[num % 10];
    num /= 10;
  }
  return res;
}


int main()
{
  // 请在此输入您的代码
  cout << count(488) << " " << count(498) << endl;
  int max_count = -1, max_num = -1;
  int A, B;
  cin >> A >> B;
  // cout << A << " " << B;
  for (int i = A; i <= B; ++i)
  {
    int i_count = count(i);
    
    if (i_count > max_count)
    {
      max_count = i_count;
      max_num = i;
    }
  }
  cout << max_num;
  return 0;
}