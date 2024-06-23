#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        double factor = (100 - discount) / 100.0;

        istringstream is(sentence);
        ostringstream os;
        os << fixed << setprecision(2);
        string word;
        while (is >> word)
        {
            if (word[0] == '$' && word.size() > 1)
            {
                bool flag = true;
                ll num = 0;
                REP(i, 1, word.size() - 1)
                {
                    if (isdigit(word[i]))
                        num = num * 10 + word[i] - '0';
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag) 
                {
                    os << "$" << num * factor << " ";
                    continue;
                }
            }
            os << word << " ";
        }
        auto res = os.str();
        res.pop_back();
        return res;
    }
};