/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
  ListNode* cur;
  int n;

  TreeNode* dfs(int l, int r) {
    if (l > r || !cur) return nullptr;

    TreeNode* root = new TreeNode();
    if (l == r) {
      root->val = cur->val;
      cur = cur->next;
      return root;
    }
    int mid = (l + r) / 2;
    root->left = dfs(l, mid - 1);
    root->val = cur->val;
    cur = cur->next;
    root->right = dfs(mid + 1, r);
    return root;
  }
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;

    cur = head;
    n = 0;
    ListNode* t = head;
    while (t) {
      ++n;
      t = t->next;
    }

    TreeNode* res = dfs(0, n);
    return res;
  }
};
