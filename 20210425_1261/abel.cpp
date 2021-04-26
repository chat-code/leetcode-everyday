/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using TN = TreeNode;
using TNP = TN*;

class FindElements {
public:
  unordered_set<int> s;

  void dfs(TNP root, int x) {
    if (!root) return;

    s.insert(x);
    root->val = x;

    dfs(root->left, x * 2 + 1);
    dfs(root->right, x * 2 + 2);
  }

  FindElements(TreeNode* root) {
    dfs(root, 0);
  }

  bool find(int target) {
    return s.find(target) != s.end();
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
