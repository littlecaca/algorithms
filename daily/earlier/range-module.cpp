#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class RangeModule {
public:
    RangeModule() {

    }
    
    void addRange(int left, int right) {
        int new_left = left, new_right = right;
        auto left_edge = lower_bound(ranges.begin(), ranges.end(), left, 
            [](const pair<int, int> &ele, int val) { return ele.second < val; });
        auto right_edge = upper_bound(ranges.begin(), ranges.end(), right,
            [](int val ,const pair<int, int> &ele) { return val < ele.first; });
        
        
        if (left_edge != ranges.end() && left >= (*left_edge).first)
            new_left = (*left_edge).first;
        auto right_temp = right_edge;
        if (right_edge != ranges.begin() && right <= (*--right_edge).second)
            new_right = (*right_edge).second;
        ranges.erase(left_edge, right_temp);
        ranges.insert(pair<int, int>(new_left, new_right));
    }
    
    bool queryRange(int left, int right) {
        cout << (*ranges.begin()).first << ", " << (*ranges.begin()).second << endl;
        cout << ranges.size() << endl;
        auto left_edge = lower_bound(ranges.begin(), ranges.end(), left, 
            [](const pair<int, int> &ele, int val) { return ele.second < val; });
        if (left_edge != ranges.end() && right <= (*left_edge).second
            && left >= (*left_edge).first)
            return true;
        return false;
    }
    
    void removeRange(int left, int right) {
        int new_left, new_right;
        auto left_edge = lower_bound(ranges.begin(), ranges.end(), left, 
            [](const pair<int, int> &ele, int val) { return ele.second < val; });
        auto right_edge = upper_bound(ranges.begin(), ranges.end(), right,
            [](int val, const pair<int, int> &ele) { return val < ele.first; });

        int old_left = -1, old_right = -1;        
        if (left_edge != ranges.end() && left >= (*left_edge).first)
        {
            old_left = (*left_edge).first;
        }
        auto right_temp = right_edge;
        if (right_edge != ranges.begin() && right < (*--right_edge).second)
        {   
            old_right = (*right_edge).second;
        }

        ranges.erase(left_edge, right_temp);
        if (old_left > 0)
        {
            ranges.insert(pair<int, int> (old_left, left));
        }
        if (old_right > 0)
        {
            ranges.insert(pair<int, int> (right, old_right));
        }
    }
private:
    set<pair<int, int>> ranges;
};