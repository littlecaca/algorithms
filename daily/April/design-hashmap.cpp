#include <algorithm>
#include <memory>
#include <vector>
#include <list>

using namespace std;


typedef list<pair<int, int>> ChainT;

class MyHashMap {
public:
    MyHashMap() : buckets(1024), capacity(1024), count(0), load_factor(1.0) {

    }
    
    void put(int key, int value) {
        if (count >= capacity * load_factor)
            extend();
        auto &tar = buckets[toIndex(key)];
        auto res = findKey(tar, key);
        if (res == tar.end())
        {
            tar.push_back({key, value});
            ++count;
        }
        else res->second = value;
    }
    
    int get(int key) {
        auto &tar = buckets[toIndex(key)];
        auto res = findKey(tar, key);

        if (res == tar.end())
            return -1;
        return res->second;
    }
    
    void remove(int key) {
        auto &tar = buckets[toIndex(key)];
        auto res = findKey(tar, key);

        if (res != tar.end())
        {
            tar.erase(res);
            --count;
        }
    }

private:
    vector<ChainT> buckets;
    size_t capacity;
    size_t count;
    double load_factor;
    hash<int> hasher;

    size_t toIndex(int key)
    {
        return hasher(key) % capacity;
    }

    void extend()
    {
        capacity *= 2;
        count = 0;
        decltype(buckets) back(capacity);
        swap(back, buckets);
        for (auto &li : back)
        {   
            for (auto &p : li)
            {
                put(p.first, p.second);
            }
        }
    }

    ChainT::iterator findKey(ChainT &tar, int key)
    {
        return find_if(tar.begin(), tar.end(), [key](const pair<int, int> &p) { return p.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */