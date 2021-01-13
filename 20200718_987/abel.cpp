//给定二叉树，按垂序遍历返回其结点值。 
//
// 对位于 (X, Y) 的每个结点而言，其左右子结点分别位于 (X-1, Y-1) 和 (X+1, Y-1)。 
//
// 把一条垂线从 X = -infinity 移动到 X = +infinity ，每当该垂线与结点接触时，我们按从上到下的顺序报告结点的值（ Y 坐标递减）
//。 
//
// 如果两个结点位置相同，则首先报告的结点值较小。 
//
// 按 X 坐标顺序返回非空报告的列表。每个报告都有一个结点值列表。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[3,9,20,null,null,15,7]
//输出：[[9],[3,15],[20],[7]]
//解释： 
//在不丧失其普遍性的情况下，我们可以假设根结点位于 (0, 0)：
//然后，值为 9 的结点出现在 (-1, -1)；
//值为 3 和 15 的两个结点分别出现在 (0, 0) 和 (0, -2)；
//值为 20 的结点出现在 (1, -1)；
//值为 7 的结点出现在 (2, -2)。
// 
//
// 示例 2： 
//
// 
//
// 输入：[1,2,3,4,5,6,7]
//输出：[[4],[2],[1,5,6],[3],[7]]
//解释：
//根据给定的方案，值为 5 和 6 的两个结点出现在同一位置。
//然而，在报告 "[1,5,6]" 中，结点值 5 排在前面，因为 5 小于 6。
// 
//
// 
//
// 提示： 
//
// 
// 树的结点数介于 1 和 1000 之间。 
// 每个结点值介于 0 和 1000 之间。 
// 
// Related Topics 树 哈希表 
// 👍 74 👎 0

// 根节点坐标设置为 0，0，然后往下 y+1, 往左 x-1, 往右 x+1
// 记录每个节点的坐标即可。同时记录每个节点的值
// 按照 x, y, val 递增的顺序排序
// 最后按照 x 聚合即可

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <tuple>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    using TI = tuple<int, int, int>;
    vector <tuple<int, int, int>> nodes;

    void dfs(TreeNode *root, int x, int y) {
        if (root == nullptr) return;
        TreeNode *left = root->left, *right = root->right;
        nodes.push_back(make_tuple(x, y, root->val));
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }

    vector <vector<int>> verticalTraversal(TreeNode *root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end(), [&](const TI &a, const TI &b) {
            if (get<0>(a) < get<0>(b)) return true;
            else if (get<0>(a) > get<0>(b)) return false;
            else {
                if (get<1>(a) < get<1>(b)) return true;
                else if (get<1>(a) > get<1>(b)) return false;
                else {
                    if (get<2>(a) < get<2>(b)) return true;
                    else return false;
                }
            }
        });
        vector <VI> res;
        int pre;
        for (int i = 0; i < nodes.size(); i++) {
            if (i) {
                int tmp = get<0>(nodes[i]);
                if (tmp == pre) {
//                    same x
                    res[res.size() - 1].push_back(get<2>(nodes[i]));
                } else {
//                    new x
                    pre = get<0>(nodes[i]);
                    res.push_back(VI{get<2>(nodes[i])});
                }
            } else {
                pre = get<0>(nodes[i]);
                res.push_back(VI{get<2>(nodes[i])});
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
