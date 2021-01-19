/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// @lc code=start
/**
 * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */
class Solution {
public:
    set<int> ns;
    void find_node(vector<TreeNode*>& v, int val, TreeNode * r) {
        if (r == nullptr || v.size() > 0) return;
        if (r->val == val) {
            v.push_back(r);
            return;
        }
        ns.insert(r->val);

        find_node(v, val, r->left);
        find_node(v, val, r->right);
        if (v.size() > 0) {
            v.push_back(r);
        }

        ns.erase(r->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int r1 = p->val, r2 = q->val;
        vector<TreeNode*> v1, v2;
        find_node(v1, r1, root);
        ns.clear();
        find_node(v2, r2, root);
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());

        int len = min(v1.size(), v2.size());
        TreeNode* res = nullptr;
        for (int i = 0; i < len; ++i) {
            if (v1[i]->val == v2[i]->val) {
                res = v1[i];
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

