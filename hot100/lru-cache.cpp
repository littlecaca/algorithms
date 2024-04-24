#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : mCapa(capacity) {

    }
    
    int get(int key) {
        auto res = dict.find(key);
        if (res == dict.end()) return -1;
        int ans = res->second->second;
        chain.erase(res->second);
        res->second = chain.insert(chain.end(), {key, ans});
    
        return ans;
    }
    
    void put(int key, int value) {
        auto res = dict.find(key);
        if (res != dict.end())
        {
            chain.erase(res->second);
            res->second = chain.insert(chain.end(), {key, value});
        }
        else
        {
            if (count < mCapa)
            {
                dict[key] = chain.insert(chain.end(), {key, value});
                ++count;
            }
            else
            {
                int k = chain.front().first;
                chain.pop_front();
                dict.erase(k);

                dict[key] = chain.insert(chain.end(), {key, value});
            }
        }
    }
private:
    int mCapa;
    int count = 0;
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    list<pair<int, int>> chain;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */