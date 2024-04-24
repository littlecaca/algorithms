#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    static const map<string, char> en_map;
    string entityParser(string text) {
        string::iterator slow = text.begin(), fast = slow;
        while (fast != text.end())
        {
            if (*fast == '&')
            {
                bool is_entity;
                for (auto &key : en_map)
                {
                    is_entity = true;
                    auto cur = fast + 1;
                    for (auto c : key.first)
                    {
                        if (cur == text.end() || c != *cur++)
                        {
                            is_entity = false;
                            break;
                        }
                    }
                    if (is_entity)
                    {
                        fast = cur;
                        *slow++ = key.second;
                        break;
                    }
                }
                if (!is_entity)
                {
                    *slow++ = *fast++;
                }
            }
            else
            {
                *slow++ = *fast++;
            }
        }
        return text.substr(0, slow - text.begin());
    }
};

const map<string, char> Solution::en_map {
        {"quot;", '\"'},
        {"apos;", '\''},
        {"amp;", '&'},
        {"gt;", '>'},
        {"lt;", '<'},
        {"frasl;", '/'},
};