#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
public:
    // 规律总结题：贪心算法
    string maximumBinaryString(string binary) {
        int first_zero = binary.find_first_of('0');
        if (first_zero == string::npos) return binary;
        int zeros = count(binary.begin() + first_zero + 1, binary.end(), '0');
        int tar = first_zero + zeros;
        binary[tar] = '0';
        fill(binary.begin(), binary.begin() + tar, '1');
        fill(binary.begin() + tar + 1,binary.end(), '1');
        return binary;
    }
};

