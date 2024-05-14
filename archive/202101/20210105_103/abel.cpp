//给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
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
// 返回锯齿形层序遍历如下： 
//
// 
//[
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 栈 树 广度优先搜索 
// 👍 398 👎 0


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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level = 1;
        vector<VI> res;
        if (!root) return res;

        queue<PIT> q;
        q.push(PIT(level, root));
        VI tmp;

        while (!q.empty()) {
            PIT t = q.front();
            q.pop();

            if (level != t.first) {
                res.push_back(tmp);
                ++level;
                tmp = {t.second->val};
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
        for (int i = 0; i < res.size(); i++) {
            if (i & 1) {
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
