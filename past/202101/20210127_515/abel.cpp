//您需要在二叉树的每一行中找到最大的值。 
//
// 示例： 
//
// 
//输入: 
//
//          1
//         / \
//        3   2
//       / \   \  
//      5   3   9 
//
//输出: [1, 3, 9]
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 124 👎 0


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
    vector<int> res;

    void dfs(TreeNode *r, int cur) {
        if (!r) return;
        if (cur > res.size()) {
            res.push_back(r->val);
        } else {
            res[cur - 1] = max(res[cur - 1], r->val);
        }

        dfs(r->left, cur + 1);
        dfs(r->right, cur + 1);
    }

    vector<int> largestValues(TreeNode *root) {
        dfs(root, 1);

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
