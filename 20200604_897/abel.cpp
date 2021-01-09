/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
 * 
 * 中序遍歷二叉樹，保存節點順序，重新構造樹
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
    void dfs(TreeNode * root, vector<TreeNode *> &res) {
        if (root == nullptr) return;
        dfs(root->left, res);
        res.push_back(root);
        dfs(root->right, res);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode *> res;
        dfs(root, res);
        TreeNode *b = new TreeNode(res[0]->val), *cur = b;
        for (int i = 1; i < res.size(); i++) {
            cur->right = new TreeNode(res[i]->val);
            cur = cur->right;
        }
        return b;
    }
};
// @lc code=end

