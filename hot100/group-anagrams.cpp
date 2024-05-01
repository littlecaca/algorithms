#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

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

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> reocord;
        for (auto &word : strs)
        {
            auto temp = word;
            sort(temp.begin(), temp.end());
            reocord[temp].push_back(word); 
        }
        vector<vector<string>> res;
        for (auto &p : reocord)
        {
            
            res.push_back(std::move(p.second));
        }
        return res;
    }
};