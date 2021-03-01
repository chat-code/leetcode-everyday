//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 105] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 459 👎 0


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
class Solution {
public:
    using PIT = pair<int, TreeNode *>;
    int minDepth(TreeNode* root) {
        queue<PIT> q;
        int res = 0, level = 1;
        if (!root) return res;
        q.push(PIT(level, root));
        while (!q.empty()) {
            PIT t = q.front();
            q.pop();

            if (!(t.second->left) && !(t.second->right)) return t.first;

            if (level != t.first) {
                level++;
            }

            if (t.second->left) q.push(PIT(level + 1, t.second->left));
            if (t.second->right) q.push(PIT(level + 1, t.second->right));
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
