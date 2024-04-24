#include <numeric>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    vector<int> v;
    Node() : val(0), left(nullptr), right(nullptr) {
        int *i = new int(12);
        val = *i;
        v.push_back(val);
    }
    Node(int val) : val(val) {}
};

const Node node;
vector<int> vv{1, 2};

class Test
{
public:
    Test() {}
    int i;
    char rr;
};

int main(int argc, char const *argv[])
{
    vector<int> sam{1, 2};
    for (auto n : sam)
    {
        cout << n << endl;
        continue;
    }
    int count = 10;
    while (count--)
    {
        int *t = new int[32];
        cout << *t << "\t";
        delete []t;
    }

    count = 10;
    while (count--)
    {
        Test *t = new Test;
        cout << t->i << endl;
        delete t;
    }
    string s;
    
    cout << accumulate(sam.begin(), sam.end(), 0) << endl;
    cout << node.val << endl;
    cout << node.v.back() << endl;
    unsigned char kk = -1;
    cout << (int)kk << endl;
    return 0;
}
