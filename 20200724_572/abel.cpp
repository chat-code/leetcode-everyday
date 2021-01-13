/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */

struct TreeNode
{
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
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;


class Solution
{
public:
    bool res;
    bool equalTree(TreeNode *a, TreeNode *b) {
        if (a == nullptr && b == nullptr) return true;
        if (a == nullptr || b == nullptr) return false;
        if (a->val != b->val) return false;
        return equalTree(a->left, b->left) && equalTree(a->right, b->right);
    }

    void dfs(TreeNode * root, TreeNode* t) {
        if (root == nullptr) return;
        if (res) return;
        if (root->val == t->val) {
            if (equalTree(root, t)) {
                res = true;
                return;
            }
        }
        dfs(root->left, t);
        dfs(root->right, t);
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        res = false;
        dfs(s, t);
        return res;
    }
};
// @lc code=end
