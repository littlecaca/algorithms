#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Trie {
public:
    Trie() : children(26), isEnd(false) {

    }
    
    void insert(string word) {
        Trie *cur = this;
        for (auto ch : word)
        {
            auto &next = cur->children[ch - 'a'];
            if (next == nullptr)
                next = new Trie;
            cur = next;
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie *res = find(word);
        return res != nullptr && res->isEnd;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

    ~Trie() {
        for (auto child : children)
            delete child;
    }
protected:
    vector<Trie *> children;
    bool isEnd;

    Trie *find(const string &prefix)
    {
        Trie *cur = this;
        for (auto ch : prefix)
        {
            cur = cur->children[ch - 'a'];
            if (cur == nullptr)
                return nullptr;
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */