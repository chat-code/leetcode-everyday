//你现在手里有一份大小为 N x N 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋单
//元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。 
//
// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - 
//x1| + |y0 - y1| 。 
//
// 如果网格上只有陆地或者海洋，请返回 -1。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[[1,0,1],[0,0,0],[1,0,1]]
//输出：2
//解释： 
//海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
// 
//
// 示例 2： 
//
// 
//
// 输入：[[1,0,0],[0,0,0],[0,0,0]]
//输出：4
//解释： 
//海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length == grid[0].length <= 100 
// grid[i][j] 不是 0 就是 1 
// 
// Related Topics 广度优先搜索 图 
// 👍 182 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
const int N = 110, INF = 0x3f3f3f3f;
int st[N][N], dis[N][N];
int dir[4][2] {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0},
};

class Solution {
public:
    using PII = pair<int, int>;
    using IPII = pair<int, PII>;
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        memset(dis, 0x3f, sizeof dis); memset(st, 0, sizeof dis);
        priority_queue<IPII, vector<IPII>, greater<IPII>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j]) { q.push(IPII(0, {i, j})); dis[i][j] = 0; }
            }
        }
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            int base = t.first; PII p = t.second;
            int x = p.first, y = p.second;
            if (st[x][y]) continue;
            st[x][y] = 1;
            for (int i = 0; i < 4; ++i) {
                int x1 = x + dir[i][0], y1 = y + dir[i][1];
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
                    if (dis[x1][y1] > base + 1) {
                        dis[x1][y1] = base + 1; q.push(IPII(dis[x1][y1], PII(x1, y1)));
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
            if (!a[i][j] && dis[i][j] != INF) res = max(res, dis[i][j]);
        return (res == 0) ? -1 : res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
