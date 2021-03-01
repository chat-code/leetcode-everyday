//给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其自底向上的层序遍历为： 
//
// 
//[
//  [15,7],
//  [9,20],
//  [3]
//]
// 
// Related Topics 树 广度优先搜索 
// 👍 410 👎 0


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<VI> res;
        queue<PIT> q;
        int cur = 0;
        q.push(PIT(0, root));
        VI tmp;
        while (!q.empty()) {
            PIT t = q.front();
            q.pop();
            if (t.second == nullptr) continue;

            if (cur == t.first) {
               tmp.push_back(t.second->val);
            } else {
                res.push_back(tmp);
                ++cur;
                tmp = VI{t.second->val};
            }

            if (t.second->left) {
                q.push(PIT(cur + 1, t.second->left));
            }
            if (t.second->right) {
                q.push(PIT(cur + 1, t.second->right));
            }
        }
        if (tmp.size()) res.push_back(tmp);
        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
