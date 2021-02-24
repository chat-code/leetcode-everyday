//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 回溯算法 
// 👍 756 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
const int N = 12;
int col[N], d1[N*2], d2[N*2], row[N];
class Solution {
public:
    using VS = vector<string>;
    vector<VS> res; int n;
    void dfs(int k) {
        if (k == n) {
            VS cur;
            for (int i = 0; i < n; ++i) {
                string s(n, '.'); s[row[i]] = 'Q';
                cur.push_back(s);
            }
            res.push_back(cur); return;
        }
        for (int i = 0; i < n; ++i) {
            if (!col[i] && !d1[k + i] && !d2[k - i + n]) {
                col[i] = d1[k + i] = d2[k - i + n] = 1;
                row[k] = i;
                dfs(k + 1);
                col[i] = d1[k + i] = d2[k - i + n] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        memset(col, 0, sizeof col);
        memset(d1, 0, sizeof d1);
        memset(d2, 0, sizeof d2);
        dfs(0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
