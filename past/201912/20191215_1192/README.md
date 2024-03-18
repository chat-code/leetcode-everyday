[1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/) 

[1192. 查找集群内的「关键连接」](https://leetcode-cn.com/problems/critical-connections-in-a-network/)

```
1192. Critical Connections in a Network
Hard


There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.


Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

- 1 <= n <= 10^5
- n-1 <= connections.length <= 10^5
- connections[i][0] != connections[i][1]
- There are no repeated connections.


1192. 查找集群内的「关键连接」

力扣数据中心有 n 台服务器，分别按从 0 到 n-1 的方式进行了编号。

它们之间以「服务器到服务器」点对点的形式相互连接组成了一个内部集群，其中连接 connections 是无向的。

从形式上讲，connections[i] = [a, b] 表示服务器 a 和 b 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。

「关键连接」是在该集群中的重要连接，也就是说，假如我们将它移除，便会导致某些服务器无法访问其他服务器。

请你以任意顺序返回该集群内的所有 「关键连接」。

 

示例 1：



输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
输出：[[1,3]]
解释：[[3,1]] 也是正确的。
 

提示：

- 1 <= n <= 10^5
- n-1 <= connections.length <= 10^5
- connections[i][0] != connections[i][1]
- 不存在重复的连接
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/critical-connections-in-a-network
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
