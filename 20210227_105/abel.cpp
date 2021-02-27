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
  using VI = vector<int>;
  VI pre, ino;
  map<int, int> m;

  TreeNode* dfs(int l, int r, int l1, int r1) {
    TreeNode* root = nullptr;
    if (l > r) return root;
    int val = pre[l];
    root = new TreeNode(val);
    int idx = m[val];
    int cntl = idx - l1, cntr = r1 - idx;
    TreeNode * left = nullptr, *right = nullptr;
    if (cntl > 0) {
      left = dfs(l + 1, l + cntl, l1, idx - 1);
    }
    if (cntr > 0) {
      right = dfs(l + cntl + 1, r, idx + 1, r1);
    }
    root->left = left;
    root->right = right;

    return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    pre = preorder;
    ino = inorder;
    int n = pre.size();
    for (int i = 0; i < n; ++i) {
      m[ino[i]] = i;
    }
    TreeNode* res = dfs(0, n - 1, 0, n - 1);
    return res;
  }
};
