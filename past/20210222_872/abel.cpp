//请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。 
//
// 
//
// 举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。 
//
// 如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。 
//
// 如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,nu
//ll,null,null,null,9,8]
//输出：true
// 
//
// 示例 2： 
//
// 输入：root1 = [1], root2 = [1]
//输出：true
// 
//
// 示例 3： 
//
// 输入：root1 = [1], root2 = [2]
//输出：false
// 
//
// 示例 4： 
//
// 输入：root1 = [1,2], root2 = [2,2]
//输出：true
// 
//
// 示例 5： 
//
// 
//
// 输入：root1 = [1,2,3], root2 = [1,3,2]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 给定的两棵树可能会有 1 到 200 个结点。 
// 给定的两棵树上的值介于 0 到 200 之间。 
// 
// Related Topics 树 深度优先搜索 
// 👍 90 👎 0


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
    using VI = vector<int>;

    void dfs(TreeNode * root, VI &cur) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            cur.push_back(root->val); return;
        }
        dfs(root->left, cur);
        dfs(root->right, cur);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        VI left, right;
        dfs(root1, left);
        dfs(root2, right);
        if (left.size() != right.size()) return false;
        for (int i = 0; i < left.size(); i++) {
            if (left[i] != right[i]) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
