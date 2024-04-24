#include <queue>

using namespace std;


class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (!bigHeap.empty() && num >= bigHeap.top())
            littleHeap.push(num);
        else bigHeap.push(num);

        if (bigHeap.size() > littleHeap.size())
        {
            littleHeap.push(bigHeap.top());
            bigHeap.pop();
        }
        else if (bigHeap.size() + 1 < littleHeap.size())
        {
            bigHeap.push(littleHeap.top());
            littleHeap.pop();
        }
    }
    
    double findMedian() {
        if (bigHeap.size() == littleHeap.size())
            return (double)(bigHeap.top() + littleHeap.top()) / 2;
        else
            return littleHeap.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> littleHeap;
    priority_queue<int> bigHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */