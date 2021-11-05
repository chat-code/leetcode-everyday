// Runtime: 24 ms, faster than 98.73% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
// Memory Usage: 19.7 MB, less than 74.90% of C++ online submissions for Find Elements in a Contaminated Binary Tree.

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
class FindElements {
public:
  FindElements(TreeNode* root) {
    //// recovery is not necessary
    // if (root) {
    //   recover(root, 0);
    // }
    this->root = root;
  }

  bool find(int target) {
    ++target;
    if (target == 1 && root) return true;
    TreeNode* itr = root;
    int t = target;
    int cnt = 0;
    while (t != 0) {
      ++cnt;
      t >>= 1;
    }
    
    for (int k = cnt - 2; k >= 0; --k) {
      if (!((target >> k) & 1)) {
        if (itr->left)
          itr = itr->left;
        else
          return false;
      } else {
        if (itr->right)
          itr = itr->right;
        else
          return false;
      }
    }
    
    return true;
  }
  
private:
   TreeNode* root;
  
private:
   void recover(TreeNode* node, int val) {
     if (!node) return ;
     node->val = val;
     recover(node->left, 2 * val + 1);
     recover(node->right, 2 * val + 2);
   }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

