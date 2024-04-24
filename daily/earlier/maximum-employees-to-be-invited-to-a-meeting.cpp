#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        vector<int> records(favorite.size());
        vector<int> steps(favorite.size());
        unordered_map<int, int> heads;
        vector<int> stack;
        int ins = 0;
        int res = 0;

        for (int i = 0; i != favorite.size(); ++i)
        {
            int count = 0;
            int j = i;
            while (records[j] == 0)
            {
                stack.push_back(j);
                records[j] = -1;
                j = i;
            }

            if (records[j] < 0 && stack.size() > 1 && j != *(stack.end() - 2))
            {
                int count = 0;
                while (!stack.empty())
                {
                    ++count;
                    if (stack.back() == j)
                    {
                        res = max(res, count);
                        break;
                    }
                    stack.pop_back();
                }
            }
            else
            {
                if (stack.size() > 1 && j == *(stack.end() - 2))
                {
                    heads[stack.back()] = stack.size();
                    heads[*(stack.end() - 2)] = 2;
                }
                int count = 0;
                if (records[j] > 0)
                {
                    ins += stack.size();
                    count = records[j];
                }

                else
                {
                    if (stack.back() == *(stack.end() - 2))
                    {
                        int count = 0;
                        
                    }
                }
            }
            stack.clear();
        }

    }        
};


