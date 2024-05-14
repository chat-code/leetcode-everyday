/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

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

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

using namespace std;
using VI = vector<int>;
using VS = vector<string>;
TreeNode* st[10000];

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        VI res;
        int tt = 0;
        TreeNode* prev = nullptr;
        while (true) {
            while (root != nullptr) {
                st[++tt] = root;
                root = root->left;
            }
            if (tt) {
                TreeNode* t = st[tt];
                if (t->right == nullptr || t->right == prev) {
                    --tt;
                    res.push_back(t->val);
                    prev = t;
                } else {
                    root = t->right;
                }
            } else break;
        }
        return res;
    }
};
// @lc code=end

