//给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。 
//
// 
//
// 示例 1: 
//输入: 
//
// "bbbab"
// 
//
// 输出: 
//
// 4
// 
//
// 一个可能的最长回文子序列为 "bbbb"。 
//
// 示例 2: 
//输入: 
//
// "cbbd"
// 
//
// 输出: 
//
// 2
// 
//
// 一个可能的最长回文子序列为 "bb"。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 只包含小写英文字母 
// 
// Related Topics 动态规划 
// 👍 391 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

const int N = 1010;
int d[N][N];

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(d, 0, sizeof d);
        int res = 1;
        for (int i = 0; i < n; ++i) d[i][i] = 1;
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i + k < n; ++i) {
                int j = i + k;
                if (s[i] == s[j]) {
                    d[i][j] = 2 + d[i + 1][j - 1];
                } else {
                    d[i][j] = max(d[i + 1][j], d[i][j - 1]);
                }
                res = max(res, d[i][j]);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
