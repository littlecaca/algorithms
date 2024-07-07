#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * 计算pattern[0:i]相等的最长前后缀
 */
void cal(vector<int> &next, const string &pattern)
{ 
    int n = pattern.size();
    next[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int cur = next[i - 1];
        char tar = pattern[i];
        while (cur > 0 && pattern[cur] != tar)
            cur = next[cur];
        
        if (pattern[cur] == tar) next[i] = cur + 1;
        else next[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    string pattern = ", but";
    string raw = "this is an error, but you know nothing about it!!!";

    vector<int> next(pattern.size());
    cal(next, pattern);
    
    int i = 0;
    for (auto c : raw)
    {
        if (pattern[i] == c)
        {
            if (++i == pattern.size())
            {
                std::cout << "Find!" << std::endl;
                break;
            }
        }
        else
            i = next[max(0, i - 1)];
    }
    
    return 0;
}
