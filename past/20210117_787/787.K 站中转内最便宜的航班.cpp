//有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。 
//
// 现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。 如果没有这样
//的路线，则输出 -1。 
//
// 
//
// 示例 1： 
//
// 
//输入: 
//n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
//src = 0, dst = 2, k = 1
//输出: 200
//解释: 
//城市航班图如下
//
//
//从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。 
//
// 示例 2： 
//
// 
//输入: 
//n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
//src = 0, dst = 2, k = 0
//输出: 500
//解释: 
//城市航班图如下
//
//
//从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。 
//
// 
//
// 提示： 
//
// 
// n 范围是 [1, 100]，城市标签从 0 到 n - 1 
// 航班数量范围是 [0, n * (n - 1) / 2] 
// 每个航班的格式 (src, dst, price) 
// 每个航班的价格范围是 [1, 10000] 
// k 范围是 [0, n - 1] 
// 航班没有重复，且不存在自环 
// 
// Related Topics 堆 广度优先搜索 动态规划 
// 👍 238 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
const int N = 110, INF = 0x3f3f3f3f;
int dis[N], bak[N];

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int dst, int K) {
       memset(dis, INF, sizeof dis);
       dis[src] = 0;
       for (int i = 0; i < K + 1; ++i) {
           memcpy(bak, dis, sizeof dis);
           for (int j = 0; j < a.size(); ++j) {
               int x = a[j][0], y = a[j][1], c = a[j][2];
               if (dis[y] > bak[x] + c) {
                   dis[y] = bak[x] + c;
               }
           }
       }
       return dis[dst] == INF ? -1 : dis[dst];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
