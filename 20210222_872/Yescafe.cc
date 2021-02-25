/*
Runtime: 4 ms, faster than 75.40% of C++ online submissions for Leaf-Similar Trees.
Memory Usage: 12.8 MB, less than 74.81% of C++ online submissions for Leaf-Similar Trees.
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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    findLeavesAndDo(root1, [&](int val) {
      leaves.push(val);
    });
    findLeavesAndDo(root2, [&](int val) {
      if (!leaves.empty() && leaves.front() != val) {
        isSimilar = false;
      }
      leaves.pop();
    });
    return isSimilar && leaves.empty();
  }

private:
  template <typename Func>
  void findLeavesAndDo(TreeNode* root, Func&& f) {
    if (root == nullptr) return ;
    if (root->left == nullptr && root->right == nullptr) {
      f(root->val);
    }
    if (!isSimilar) return ;
    findLeavesAndDo(root->left, f);
    findLeavesAndDo(root->right, f);
  }

private:
  std::queue<int> leaves;
  bool isSimilar = true;
};
