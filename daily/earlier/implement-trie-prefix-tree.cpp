#include <vector>
#include <memory>
#include <string>

using namespace std;

class Trie {
public:
    Trie() : children(vector<Trie *>(26, nullptr)), isEnd(false) {

    }
    
    void insert(const string &word) {
       Trie *cur = this;
       for (char ch : word)
       {
            Trie *&next = cur->children[ch - 'a'];
            if (!next)
                next = new Trie();
            cur = next;
       }
       cur->isEnd = true;
    }
    
    bool search(const string &word) {
        Trie *cur = searchPrefix(word);
        if (cur && cur->isEnd)
            return true;
        return false;
    }
    
    bool startsWith(const string &prefix) {
        if (searchPrefix(prefix) != nullptr)
            return true;
        return false;
    }

    ~Trie()
    {
        for (auto c : children)
        {
            delete c;
        }
    }

private:
    Trie *searchPrefix(const string &word)
    {
        Trie *cur = this;
        for (char ch : word)
        {
            Trie *&next = cur->children[ch - 'a'];
            if (!next)
            {
                return nullptr;
            }
            else 
            {
                cur = next;
            }
        }
        return cur;
    }
    vector<Trie *> children;
    bool isEnd;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */