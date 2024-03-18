/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        int len = int(moves.size());
        for (int i = 0; i < len; i++) {
            switch (moves[i]) {
                case 'R': x++; break;
                case 'L': x--; break;
                case 'U': y++; break;
                case 'D': y--; break;
                default: break;
            }
        }
        return (x == 0 && y == 0);
    }
};
// @lc code=end

