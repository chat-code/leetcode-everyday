class Solution {
public:
  bool check(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return true;
  }
  bool isSymmetric(TreeNode* root) {
    stack<TreeNode*> stk;
    if (!root) return true;
    if (!check(root->left, root->right)) return false;

    if (root->left) {
      stk.push(root->left); stk.push(root->right);
    }

    while (!stk.empty()) {
      TreeNode* p1, *p2;
      p1 = stk.top(); stk.pop();
      p2 = stk.top(); stk.pop();
      if (p1->val != p2->val) return false;

      if (!check(p1->left, p2->right)) return false;
      if (p1->left) {
        stk.push(p1->left); stk.push(p2->right);
      }

      if (!check(p1->right, p2->left)) return false;
      if (p1->right) {
        stk.push(p1->right), stk.push(p2->left);
      }
    }
    return true;
  }
};
