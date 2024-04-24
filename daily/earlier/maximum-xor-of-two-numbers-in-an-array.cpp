#include <unordered_set>
#include <vector>


using namespace std;

#define HIGHEST_BITS 30

// ===========================
//      哈希表 + 位级二分法
// ===========================

// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int x = 0;
//         for (int i = HIGHEST_BITS; i >= 0; --i)
//         {   
//             unordered_set<int> hash;
//             int x_next = x * 2 + 1;
//             bool flag = false;
//             for (int num : nums)
//             {
//                 hash.insert(num >> i);
//                 if (hash.count((num >> i) ^ x_next))
//                 {
//                     x = x_next;
//                     flag = true;
//                     break;
//                 }
//             }
//             if (!flag) x = x_next - 1;
//         }
//         return x;
//     }
// };


// ==================
//      字典树
// ==================


struct Tries
{
    Tries *left = nullptr;
    Tries *right = nullptr;
    // ~Tries()
    // {
    //     delete left;
    //     delete right;
    // }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int m = 0;
        for (int i = 1; i != nums.size(); ++i)
        {
            add(nums[i - 1]);
            m = max(m, check(nums[i]));
        }
        return m;
    }


private:
    void add(int num)
    {
        Tries *cur = &root;
        for (int i = HIGHEST_BITS; i >= 0; --i)
        {
            int target = num & (1 << i);
            if (target)
            {
                if (!cur->right)
                    cur->right = new Tries();
                cur = cur->right;
            }
            else
            {
                if (!cur->left)
                    cur->left = new Tries();
                cur = cur->left;
            }
        }
    }
    
    int check(int num)
    {
        Tries *cur = &root;
        int x = 0;
        for (int i = HIGHEST_BITS; i >= 0; --i)
        {
            int target = num & (1 << i);
            if (target)
            {
                if (!cur->left)
                {
                    x *= 2;
                    cur = cur->right;
                }
                else
                {
                    x = x * 2 + 1;
                    cur = cur->left;
                }
            }
            else 
            {
                if (!cur->right)
                {
                    x *= 2;
                    cur = cur->left;
                }
                else
                {
                    x = x * 2 + 1;
                    cur = cur->right;
                }
            }
        }
        return x;
    }

    Tries root;
};