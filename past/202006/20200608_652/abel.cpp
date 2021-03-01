/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 * 
 * 後序遍歷二叉樹，把節點拼接成字符串，放到 map 裏面，如果之前遇到過，說明存在重複的子樹
 * 
 * 由於整棵樹拼接成字符串可能過長，可以這樣優化：
 * 每顆新的子樹樹分配一個 ID，用 ID 來代替整棵樹。這樣可以保證一棵樹的 key 的字符串表示的
 * 長度在 3 個整數的長度範圍內
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
class Solution2 {
public:
    map<string, int> cnts;
    map<string, TreeNode*> roots;

    string dfs(TreeNode * root) {
        if (root == nullptr) return "";
        string t1 = dfs(root->left);
        string t2 = dfs(root->right), res;
        res = t1 + "-" + t2;
        res = res + "-" + to_string(root->val);
        roots[res] = root;
        cnts[res]++;
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        dfs(root);
        for (auto &x : cnts) {
            if (x.second > 1) {
                res.push_back(roots[x.first]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<TreeNode*> resv;
    map<string, int> uids;
    map<int, int> cnts;
    int id;

    int dfs(TreeNode * root) {
        if (root == nullptr) return 0;
        int t1 = dfs(root->left);
        int t2 = dfs(root->right);
        string res;

        res = to_string(t1) + "-" + to_string(t2) + "-" + to_string(root->val);
        if (uids[res] == 0) {
            uids[res] = ++id;
        }
        int uid = uids[res];
        cnts[uid]++;
        if (cnts[uid] == 2) {
            resv.push_back(root);
        }
        return uid;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        id = 1;
        dfs(root);
        return resv;
    }
};
// @lc code=end

