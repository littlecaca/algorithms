#include <functional>
#include <vector>

using namespace std;

class MyHashSet {
public:
    MyHashSet() {

    }
    
    void add(int key) {
        if (find(key) == -1)
        {
            if (count >= capacity / 2)
                extend();
            ++count;
            insert(key);
        }
    }
    
    void remove(int key) {
        int tar = find(key);
        if (tar != -1)
        {
            buckets[tar] = -2;
            --count;
        }
    }
    
    bool contains(int key) {
        int tar = find(key);
        return tar != -1;
    }

private:
    int count = 0;
    int capacity = 1;
    vector<int> buckets = vector<int>(1, -1);

    int find(int key)
    {
        int next = hash(key);
        while (buckets[next] != key && buckets[next] != -1)
            next = (next + 1) % capacity;
        return buckets[next] == -1 ? -1 : next;
    }

    int hash(int key)
    {
        return std::hash<int>()(key) % capacity;
    }

    void extend()
    {
        capacity = capacity * 2;
        vector<int> back(capacity, -1);
        swap(back, buckets);
        for (auto i : back)
            if (i != -1) insert(i);
    }

    void insert(int key)
    {
        int next = hash(key);
        while (buckets[next] >= 0)
            next = (next + 1) % capacity;
        buckets[next] = key;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */