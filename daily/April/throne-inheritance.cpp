#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct Person
{
    Person(const string &n) : name(n) {}
    string name;
    vector<shared_ptr<Person>> sons;
    bool isAlive = true;
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        query[kingName].reset(new Person(kingName));
        king = query[kingName];
    }
    
    void birth(string parentName, string childName) {
        query[childName].reset(new Person(childName));
        query[parentName]->sons.emplace_back(query[childName]);
    }
    
    void death(string name) {
        query[name]->isAlive = false;
    }
    
    vector<string> getInheritanceOrder() {
        // dfs
        vector<string> trace;
        dfs(trace, king);
        return trace;
    }

    void dfs(vector<string> &trace, shared_ptr<Person> cur)
    {
        if (cur->isAlive)
            trace.push_back(cur->name);
        for (auto child : cur->sons)
        {
            dfs(trace, child);
        }
    }

    unordered_map<string, shared_ptr<Person>> query;
    shared_ptr<Person> king;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */