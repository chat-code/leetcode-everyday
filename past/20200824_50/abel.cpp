/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    using ll = long long;
    double qmi(double a, ll n) {
        double res = 1;
        if (a == 0) return 0;
        if (n == 0 || a == 1) return 1;
        while (n) {
            if (n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
    double myPow(double x, int n) {
        ll k = n;
        if (k < 0) k = -k;
        double res {qmi(x, k)};
        if (n < 0) res = 1.0 / res;
        return res;
    }
};
// @lc code=end

