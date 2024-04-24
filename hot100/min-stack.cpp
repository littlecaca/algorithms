#include <vector>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> sta;
    vector<int> que;

    MinStack() {

    }
    
    void push(int val) {
        que.push_back(val);
        if (sta.empty() || val <= sta.top())
        {
            sta.push(val);
        }
    }
    
    void pop() {
        auto tar = que.back();
        que.pop_back();
        if (tar == sta.top())
        {
            sta.pop();
        }
    }
    
    int top() {
        return que.back();
    }
    
    int getMin() {
        return sta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */