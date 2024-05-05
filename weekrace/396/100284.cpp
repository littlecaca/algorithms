#include <cstdlib>
#include <set>
#include <string>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}


bool isVowel(const string &word)
{
    static set<char> vowels = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool flag = false, flag2 = false;

    for (auto c : word)
    {
        // if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) return false;
        if (vowels.find(c) != vowels.end())
            flag = true;
        else if (c == '@' || c == '#' || c == '$')
            return false;
        else if (!isdigit(c))
            flag2 = true;
    }
    if (flag && flag2) return true;
    return false;

}

class Solution {
public:
    bool isValid(string word) {
        if (word.size() > 2 && isVowel(word)) return true;
        return false;
    }
};