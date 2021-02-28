//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例： 
//二叉树：[3,9,20,null,null,15,7], 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层序遍历结果： 
//
// 
//[
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索 
// 👍 786 👎 0


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
    using PIT = pair<int, TreeNode *>;

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<VI> res;
        if (!root) return res;

        queue<PIT> q;
        int level = 1;
        q.push(PIT(level, root));
        VI tmp;

        while (!q.empty()) {
           PIT t = q.front();
           q.pop();

           if (t.first != level) {
               res.push_back(tmp);
               ++level;
               tmp = VI{t.second->val};
           } else {
               tmp.push_back(t.second->val);
           }

           if (t.second->left) {
               q.push(PIT(level + 1, t.second->left));
           }
           if (t.second->right) {
               q.push(PIT(level + 1, t.second->right));
           }
        }
        if (tmp.size()) res.push_back(tmp);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
