#include <vector>

using namespace std;

/**
 * 2536. 子矩阵元素加 1
 * 给你一个正整数 n ，表示最初有一个 n x n 、下标从 0 开始的整数矩阵 mat ，矩阵中填满了 0 。
 * 
 * 另给你一个二维整数数组 query 。针对每个查询 query[i] = [row1i, col1i, row2i, col2i] ，请你执行下述操作：
 * 
 * 找出 左上角 为 (row1i, col1i) 且 右下角 为 (row2i, col2i) 的子矩阵，将子矩阵中的 每个元素 加 1 。
 * 也就是给所有满足 row1i <= x <= row2i 和 col1i <= y <= col2i 的 mat[x][y] 加 1 。
 * 返回执行完所有操作后得到的矩阵 mat 。
*/

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n));
        // 一维差分
        // for (auto &query : queries) {
        //     for (int i = query[0]; i <= query[2]; ++i) {
        //         ++res[i][query[1]];
        //         if (query[3] + 1 < n) {
        //             --res[i][query[3] + 1];
        //         }
        //     }
        // }
        // for (auto& line : res) {
        //     int cur = 0;
        //     for (int j = 0; j < n; ++j) {
        //         cur += line[j];
        //         line[j] = cur;
        //     }
        // }

        // 二维差分
        /**
         * 首先介绍二维前缀和的概念，二维前缀和是指从原点到某一顶点(i, j)所确定的矩阵的
         * 元素和。具体来说，原矩阵中mat[i][j]的值为SUM(diff[0:i, 0:j])。
         * 由于前缀和与差分互为逆运算，那么二维差分数组中:
         * diff[i][j] = mat[i][j] - mat[i - 1][j] - mat[i][j - 1] + mat[i - 1][j - 1]
         * mat[i - 1][j - 1]代表的是mat[i - 1][j]与mat[i][j - 1]的重合部分，需要加回来    
        */
        for (auto& q : queries) {
            auto r1 = q[0], c1 = q[1];
            auto r2 = q[2], c2 = q[3];
            ++res[r1][c1];
            if (c2 + 1 < n) {
                --res[r1][c2 + 1];
            }
            if (r2 + 1 < n) {
                --res[r2 + 1][c1];
            }
            if (c2 + 1 < n && r2 + 1 < n) {
                ++res[r2 + 1][c2 + 1];
            }
        }

        // 二维前缀和
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] += i > 0 ? res[i - 1][j] : 0;
                res[i][j] += j > 0 ? res[i][j - 1] : 0;
                res[i][j] -= i > 0 && j > 0 ? res[i - 1][j - 1] : 0;
            }
        }
        return res;
    }
};
