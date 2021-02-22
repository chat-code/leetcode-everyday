//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//给定如下二叉树，以及目标和 sum = 22， 
//
//               5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// 
//
// 返回: 
//
// [
//   [5,4,11,2],
//   [5,8,4,5]
//]
// 
// Related Topics 树 深度优先搜索 
// 👍 426 👎 0


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
    vector <VI> res;
    int target;

    void dfs(TreeNode *root, int sum) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            cur.push_back(root->val);
            if (sum == target) {
                res.push_back(cur);
            }
            cur.pop_back();
            return;
        }

        sum += root->val;
        cur.push_back(root->val);
        dfs(root->left, sum);
        dfs(root->right, sum);
        cur.pop_back();
    }

    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        cur = VI(), res = vector<VI>(), target = targetSum;

        dfs(root, 0);

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
