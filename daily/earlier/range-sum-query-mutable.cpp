#include <numeric>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) : eles(nums) {

    }
    
    void update(int index, int val) {
        eles[index] = val;
    }
    
    int sumRange(int left, int right) {
        
        return accumulate(eles.begin() + left, eles.begin() + right + 1, 0);
    }
    
private:
    vector<int> eles;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */