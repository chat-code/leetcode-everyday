/*
Runtime: 4 ms, faster than 84.62% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.3 MB, less than 86.94% of C++ online submissions for Symmetric Tree.
*/

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
  bool isSymmetric(TreeNode* root) {
    return isSymmetricAux(root->left, root->right);
  }

  bool isSymmetricAux(TreeNode* left, TreeNode* right) {
    if (left != nullptr && right != nullptr) {
      return left->val == right->val
        && isSymmetricAux(left->left, right->right)
        && isSymmetricAux(left->right, right->left);
    } else if (left == nullptr && right == nullptr) {
      return true;
    }
   return false;
  }
};
