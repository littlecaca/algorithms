#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class Test
{
public:
    Test(int ii1) : i1(ii1), i2(i1) {
        cout << i1 << endl;
        cout << i2 << endl;
    }

    int i1, i2;    
};

int main(int argc, char *argv[])
{
    vector<int> sam{};
    if (sam.begin() == sam.end())
    {
        cout << "yes" << endl;
    }
    string s = "sda";
    s.append(" ");
    string::reverse_iterator i = s.rbegin();
    s.append("sa");
    cout << s << endl;
    stack<int> mys;

    queue<int> q;
    cout << string() + char('}' + 1) << endl;
    return 0;
}