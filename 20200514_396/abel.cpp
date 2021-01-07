/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long int sum = 0, len = int(A.size());
        if (len == 0 || len == 1) return 0;
        long long  res;
        long long int S = 0;
        for (int i = 0; i < len; ++i) {
            S += i * A[i];
            sum += A[i];
        }
        res = S;

        for (int i = 1; i < len; ++i) {
            S = S - sum + len*A[i-1];
            res = max(res, S);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> v{4, 3, 2, 6};
    Solution a;
    a.maxRotateFunction(v);
}