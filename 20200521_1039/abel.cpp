/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int d[55][55];
        memset(d, 0x3f3f3f3f, sizeof(d));
        int len = int(A.size());
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i == j || i+1 == j) {
                    d[i][j] = 0;
                }
            }
        }

        for (int k = 2; k < len; k++) {
            for (int i = 0; i + k < len; i++) {
                int j = i + k;
                for (int m = i + 1; m < j; m++) {
                    d[i][j] = min(d[i][j], d[i][m] + d[m][j] + A[i]*A[j]*A[m]);
                }
            }
        }
        return d[0][len-1];
    }
};
// @lc code=end

