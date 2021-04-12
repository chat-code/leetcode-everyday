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
  bool isleaf(TreeNode* root) {
    return root && root->left == nullptr && root->right == nullptr;
  }

  int sumOfLeftLeaves(TreeNode* root) {
    int res = 0;
    if (!root) return res;

    auto left = root->left, right = root->right;

    if (isleaf(left)) res += left->val;
    else res += sumOfLeftLeaves(left);

    if (!isleaf(right)) res += sumOfLeftLeaves(right);

    return res;
  }
};
