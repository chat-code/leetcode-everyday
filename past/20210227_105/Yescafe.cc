/*
Runtime: 16 ms, faster than 87.89% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 25.9 MB, less than 75.20% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
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

// 1 <= `preorder.length` <= 3000
// `preorder` and `inorder` consist of *unique* values.

#include <algorithm>
#include <iterator>

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeAux(preorder, inorder, 0u, 0u, preorder.size());
  }

private:
  TreeNode* buildTreeAux(vector<int>& preorder, vector<int>& inorder, 
                         ::size_t stp, ::size_t sti, ::size_t size) {
    if (size == 0u) return nullptr;   // empty tree
    auto val = preorder[stp];   // present tree->val
    auto fnd = // receive an input iterator
      std::find(inorder.begin() + sti, inorder.begin() + sti + size, val);
    auto dist = std::distance(inorder.begin() + sti, fnd);
    
    // `dist` is the size of the left child
    auto left = buildTreeAux(preorder, inorder, stp + 1, sti, dist);
    // `size - 1 - dist` is the size of the right child
    auto right = buildTreeAux(preorder, inorder, stp + 1 + dist, sti + dist + 1, size - 1 - dist);
    
    return new TreeNode(val, left, right);
  }
};