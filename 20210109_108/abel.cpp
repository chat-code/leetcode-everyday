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
  int n;
  vector<int> a;

  TreeNode* dfs(int l, int r) {
    if (l > r) return nullptr;
    TreeNode *root = new TreeNode();
    int mid = (l + r) / 2;
    root->left = dfs(l, mid - 1);
    root->val = a[mid];
    root->right = dfs(mid + 1, r);
    return root;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    n = nums.size();
    a = nums;
    return dfs(0, n - 1);
  }
};
