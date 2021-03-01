/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 * 
 * 對兩棵樹分別進行中序遍歷，然後歸併兩個有序數組即可
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;


class Solution {
public:
    void dfs(TreeNode * root, VI& vals) {
        if (root == nullptr) return;
        dfs(root->left, vals);
        vals.push_back(root->val);
        dfs(root->right, vals);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        VI vals1, vals2;
        dfs(root1, vals1);
        dfs(root2, vals2);
        VI res;
        int len1 = vals1.size(), len2 = vals2.size(), i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (vals1[i] <= vals2[j]) {
                res.push_back(vals1[i]);
                ++i;
            } else {
                res.push_back(vals2[j]);
                ++j;
            }
        }
        while (i < len1) {
            res.push_back(vals1[i]);
            ++i;
        }
        while (j < len2) {
            res.push_back(vals2[j]);
            ++j;
        }
        return res;
    }
};
// @lc code=end

