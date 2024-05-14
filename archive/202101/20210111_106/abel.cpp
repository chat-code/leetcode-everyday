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
  map<int, int> m;
  VI ino, pos;

  TreeNode* dfs(int l1, int r1, int l2, int r2) {
    TreeNode* root {};
    if (l1 > r1) return root;
    int val = pos[r2];
    root = new TreeNode(val);
    int idx = m[val], cnt1 = idx - l1, cnt2 = r1 - idx;
    if (cnt1 > 0) {
      root->left = dfs(l1, idx - 1, l2, l2 + cnt1 - 1);
    }
    if (cnt2 > 0) {
      root->right = dfs(idx + 1, r1, r2 - cnt2, r2 - 1);
    }

    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    ino = inorder;
    pos = postorder;
    for (int i = 0; i < n; ++i) {
      m[ino[i]] = i;
    }
    TreeNode* res = dfs(0, n - 1, 0, n - 1);
    return res;
  }
};
