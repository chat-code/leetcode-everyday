/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
// Your runtime beats 49.3 % of cpp submissions
// Your memory usage beats 92.86 % of cpp submissions (18.7 MB)

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
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};
// @lc code=end

