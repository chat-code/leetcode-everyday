/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
 * 
 * 求出左右子樹的到葉子節點的最大值，如果左右子樹與父節點的和小於 limit，那麼刪除掉這個子樹
 * 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

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
#include <cmath>
#include <cstdlib>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int top;
    int min_x = -0x3f3f3f3f;
    int dfs(TreeNode * root, int sum) {
        if (root == NULL) return min_x;
        if (root->left == NULL && root->right == NULL) return root->val;
        int left = dfs(root->left, sum + root->val), 
            right = dfs(root->right, sum + root->val);
        int t1 = left + sum + root->val,
            t2 = right + sum + root->val;
        if (t1 < top) {
            root->left = nullptr;
            left = min_x;
        }
        if (t2 < top) { 
            root->right = nullptr;
            right = min_x;
        }

        return root->val + max(left, right);
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        top = limit;
        int cur = dfs(root, 0);
        if (cur < limit) return nullptr;
        return root;
    }
};
// @lc code=end

