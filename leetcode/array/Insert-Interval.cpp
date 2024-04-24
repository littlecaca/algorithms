#include <algorithm>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int left = newInterval[0], right = newInterval[1];
//         int nl, nr;
//         vector<vector<int>>::iterator rl, rr;
//         bool lf = false, rf = false;

//         for (auto i = intervals.begin(); i != intervals.end(); ++i)
//         {
//             if (left <= (*i)[1] && left >= (*i)[0])
//             {
//                 nl = (*i)[0];
//                 lf = true;
//                 rl = i;
//             }
//             if (!lf && left < (*i)[0])
//             {
//                 nl = left;
//                 lf = true;
//                 rl = i;
//             }
//             if (right >= (*i)[0] && right <= (*i)[1])
//             {
//                 nr = (*i)[1];
//                 rf = true;
//                 rr = i + 1;
//             }
//             if (!rf && right < (*i)[0])
//             {
//                 nr = right;
//                 rf = true;
//                 rr = i;
//             }
//         }
        
//         if (!lf)
//         {
//             intervals.push_back({left, right});
//         }
//         if (lf && !rf)
//         {
//             intervals.erase(rl, intervals.end());
//             intervals.push_back({nl, right});
//         }
//         if (lf && rf)
//         {
//             intervals.erase(rl, rr);
//             intervals.insert(rl, {nl, nr});
//         }
//         return intervals;
//     }
// };


// int main(int argc, char const *argv[])
// {
//     vector<vector<int>> v{{1, 3}, {6, 9}};
//     vector<int> i{2, 5};
//     Solution().insert(v, i);
//     return 0;
// }


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto beg = intervals.begin(), end = intervals.end();
        int &left = newInterval[0], &right = newInterval[1];

        // 用的二分查找
        auto l = lower_bound(beg, end, left, [](auto& a, int b) { return a[1] < b; });
        auto r = upper_bound(  l, end, right, [](int b, auto& a) { return a[0] > b; });

        if (l != end) left = min(left, l[0][0]);
        if (r != beg) right = max(right, r[-1][1]);

        intervals.insert(intervals.erase(l, r), newInterval);
        return intervals;
    }
};