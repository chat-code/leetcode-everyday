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
  int min(TreeNode* root) {
    if (root == nullptr) return -1;
    int cur = root->val;
    if (root->left != nullptr) { cur = ::min(cur, min(root->left)); }
    if (root->right != nullptr) { cur = ::min(cur, min(root->right)); }
    return cur;
  }

  int max(TreeNode* root) {
    if (root == nullptr) return -1;
    int cur = root->val;
    if (root->left != nullptr) { cur = ::max(cur, max(root->left)); }
    if (root->right != nullptr) { cur = ::max(cur, max(root->right)); }
    return cur;
  }

  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    bool left = false, right = false;
    if (root->left != nullptr) {
      if (max(root->left) >= root->val) return false;
      left = isValidBST(root->left);
    } else left = true;
    if (root->right != nullptr) {
      if (min(root->right) <= root->val) return false;
      right = isValidBST(root->right);
    } else right = true;
    return left && right;
  }
};
