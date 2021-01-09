/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 * 
 * 如果左子節點等於根節點，那麼計算左子樹的解；如果右子節點等於根節點，那麼計算右子樹的解，否則右子樹的解就是右子節點
 *      左子樹的解和右子樹的解取較小的即爲整個樹的解。先判斷是否是 -1
 * 右邊同理
 * 
 * （好像思路有點兒亂……）
 */

#include <bits/stdc++.h>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// @lc code=start
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
    bool cmp(const TreeNode *a, const TreeNode *b) const {
        return a->val == b->val;
    }
    int findSecondMinimumValue(TreeNode* root) {
        TreeNode *left = root->left, *right = root->right;
        int res = INT_MAX, t1, t2;
        if (left == nullptr && right == nullptr) return -1;

        if (cmp(left, root)) {
            t1 = findSecondMinimumValue(left);
            if (cmp(right, root)) {
                t2 = findSecondMinimumValue(right);
            } else {
                t2 = right->val;
            }
        } else if (cmp(right, root)) {
            t1 = findSecondMinimumValue(right);
            if (cmp(left, root)) {
                t2 = findSecondMinimumValue(left);
            } else t2 = left->val;
        }

        if (t1 == -1) res = t2;
        else if (t2 == -1) res = t1;
        else res = min(t1, t2);
        return res;
    }
};
// @lc code=end

