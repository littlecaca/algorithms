#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // 请在此输入您的代码
    vector<string> lines;
    int count;
    cin >> count;
    string line;
    while (count--)
    {
        cin >> line;
        lines.push_back(std::move(line));
    }

    auto comp = [](string &s1, string &s2) -> bool {
        // 笨死我了 55555
        return s1 + s2 < s2 + s1;
    };

    sort(lines.begin(), lines.end(), comp);

    for (auto &line : lines)
    {
        cout << line;
    }
    return 0;
}