#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <numeric>
#include <iostream>
#include <climits>
#include <forward_list>
#include <functional>

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

# define REP(i,a,b) for(int i = a; i <= b; ++i)
# define _REP(i,a,b) for(int i = a; i >= b; --i)
# define DEBUG(num) cout << "debug: " << num << endl;

template <typename T>
bool chmin(T &a, const T &b)
{
	if (a <= b) return false;
	a = b;
	return true;
}


class Solution {
public:
    int longestAwesome(string s) {
        // 状态压缩 + 前缀和 + 哈希表
        unordered_map<int, int> record;
        int ans = 1;
        int last = 0;
        auto add = [&](int last, char c) -> int {
            return last ^ (1 << (c - '0'));
        };
        record.insert({0, -1});
        REP(i, 0, s.size() - 1)
        {
            last = add(last, s[i]);

            // 区分奇数与偶数个元素
            REP(j, 0, 9)
            {
                int odd = last ^ (1 << j);
                auto odd_tar = record.find(odd);
                if (odd_tar != record.end() && (i - odd_tar->second) % 2)
                    ans = max(ans, i - odd_tar->second);
            }

            auto tar = record.find(last);
            if (tar != record.end())
                ans = max(ans, i - tar->second);
            else
                record.insert({last, i});
        }
        return ans;
    }
};