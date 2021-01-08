/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 * 
 * f[i][j] 表示区间 i,j 的最大数字
 * d[i][j] 表示区间 i,j 的非叶子节点的最小总和
 * 画图可以得到递推公式：
 * d[i][j] = max(d[i][m]+d[m+1][j]+f[i][m]*f[m+1][j])
 * 
 * 相当于两次区间 DP
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int f[50][50];
    long long d[50][50];
    int mctFromLeafValues(vector<int>& arr) {
        int n = int(arr.size());
        memset(f, 0, sizeof f);
        memset(d, 0x3f3f3f3f, sizeof d);
        for (int i = 0; i < n; ++i) {
            f[i][i] = arr[i];
            d[i][i] = 0;
        }
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i + k < n; ++i) {
                int j = i + k;
                for (int m = i; m < j; m++) {
                    f[i][j] = max(f[i][m], f[m+1][j]);
                }
            }
        }
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i + k < n; ++i) {
                int j = i + k;
                if (k == 1) {
                    d[i][j] = arr[i] * arr[j];
                    continue;
                }
                for (int m = i; m < j; m++) {
                    d[i][j] = min(
                        d[i][j],
                        d[i][m] + d[m+1][j] +
                        f[i][m] * f[m+1][j]
                    );
                }
            }
        }
        return int(d[0][n-1]);
    }
};
// @lc code=end

