#include <map>
#include <unordered_map>
#include <vector>

using namespace std;


class SnapshotArray {
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        working[index] = val;
    }
    
    int snap() {
        record.push_back(std::move(working));
        working.clear();
        return snap_times++;
    }
    
    int get(int index, int snap_id) {
        while (snap_id >= 0)
        {
            if (record[snap_id].find(index) != record[snap_id].end())
                return record[snap_id][index];
            --snap_id;
        }
        return 0;
    }

private:
    vector<unordered_map<int, int>> record;
    unordered_map<int, int> working;
    size_t snap_times = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);

 */