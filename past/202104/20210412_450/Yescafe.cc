/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
// Runtime: 36 ms, faster than 36.30% of C++ online submissions for Delete Node in a BST.
// Memory Usage: 32.6 MB, less than 93.27% of C++ online submissions for Delete Node in a BST.

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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;  // specified
    TreeNode *current = root, *parent = nullptr;
    while (current) {
      if (current->val == key) break;
      parent = current;     // iteration
      if (key < current->val) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    if (!current) {     // not fount
      return root;
    }

    // sub-tree only has half children
    if (!current->left || !current->right) {   // at least 1 child is null
      auto child = current->left ? : (current->right ? : nullptr);
      if (parent) {    // unlink from parent node
        if (parent->left == current)
          parent->left = child;
        else
          parent->right = child;
      } else {
        root = child;
      }
      delete current;
    } else {        // complete
      auto left = current->left, right = current->right;
      if (parent) {
        if (parent->left == current)
          parent->left = left;
        else
          parent->right = left;
      } else {
        root = left;
      }
      delete current;
      TreeNode *itr = left, *itr2 = nullptr;
      while (itr) {
        itr2 = itr;
        if (right->val < itr->val) {
          itr = itr->left;
        } else {
          itr = itr->right;
        }
      }
      if (right->val < itr2->val) {
        itr2->left = right;
      } else {
        itr2->right = right;
      }
    }

    return root;
  }
};
// @lc code=end

