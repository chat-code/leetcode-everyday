//给定一个二叉树，返回所有从根节点到叶子节点的路径。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//
// 输入:
//
//   1
// /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3 
// Related Topics 树 深度优先搜索 
// 👍 444 👎 0


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
    VI cur;
    vector<string> res;

    void dfs(TreeNode * root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            cur.push_back(root->val);

            string t;
            for (int i = 0; i < cur.size(); ++i) {
                if (i == 0) t = to_string(cur[i]);
                else t = t + "->" + to_string(cur[i]);
            }
            res.push_back(t);

            cur.pop_back();
            return;
        }

        cur.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        cur.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        res = vector<string>();
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
