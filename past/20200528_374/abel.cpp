/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 * 
 * 二分，注意取平均值的時候不要溢出
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int cur = n / 2;
        int g = guess(cur);
        while (g != 0) {
            if (g > 0) {
                low = cur + 1;
            } else {
                high = cur - 1;
            }
            cur = (high - low) / 2 + low;
            g = guess(cur);
        }
        return cur;
    }
};
// @lc code=end

