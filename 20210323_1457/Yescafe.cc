/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
// Your runtime beats 66.41 % of cpp submissions
// Your memory usage beats 54.14 % of cpp submissions (180.2 MB)

#include <vector>

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
  Solution() {
    for (auto& a : counter) a = 0;
  }

  int pseudoPalindromicPaths(TreeNode* root) {
    if (root == nullptr) return 0;
    int count = 0;
    pseudoPalindromicPathsAux(root, count);
    return count;
  }

private:
  bool isPathPalindromic() {
    int odd_count = 0;
    for (int k = 1; k <= 9; ++k)
      if (counter[k] & 1)
        ++odd_count;
    if (odd_count <= 1)
      return true;
    return false;
}

  void pseudoPalindromicPathsAux(TreeNode* node, int& count) {
    if (node == nullptr) return ;

    ++counter[node->val];
    if (node->left == nullptr && node->right == nullptr && isPathPalindromic()) {
      ++count;
    }

    pseudoPalindromicPathsAux(node->left, count);
    pseudoPalindromicPathsAux(node->right, count);
    --counter[node->val];
  }
private:
  int counter[11];
};
// @lc code=end

// [2,3,1,3,1,null,1]\n[9,5,4,5,null,2,6,2,5,null,8,3,9,2,3,1,1,null,4,5,4,2,2,6,4,null,null,1,7,null,5,4,7,null,null,7,null,1,5,6,1,null,null,null,null,9,2,null,9,7,2,1,null,null,null,6,null,null,null,null,null,null,null,null,null,5,null,null,3,null,null,null,8,null,1,null,null,8,null,null,null,null,2,null,8,7]
