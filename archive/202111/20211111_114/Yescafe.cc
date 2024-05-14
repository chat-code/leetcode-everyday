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
  void flatten(TreeNode* root) {
    if (!root) return ;
    leaf = new TreeNode;
    preorder(root);
  }

private:
  void preorder(TreeNode* node) {
    if (!node) return ;
    auto left = node->left;
    auto right = node->right;

    leaf->left = nullptr;
    leaf = leaf->right = node;

    preorder(left);
    preorder(right);
  }

  TreeNode* leaf;
};
