//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。 
//
// 
//
// 示例： 
//
// 输入：
//
//   1
//    \
//     3
//    /
//   2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
// 
//
// 
//
// 提示： 
//
// 
// 树中至少有 2 个节点。 
// 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 
//相同 
// 
// Related Topics 树 
// 👍 224 👎 0

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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
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
    int res;

    int find_min(TreeNode *root) {
        if (root->left == nullptr)
            return root->val;
        return find_min(root->left);
    }

    int find_max(TreeNode *root) {
        if (root->right == nullptr)
            return root->val;
        return find_max(root->right);
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;
        if (root->left == nullptr) {
            int t1 = find_min(root->right);
            res = min(res, abs(t1 - root->val));
            dfs(root->right);
        } else if (root->right == nullptr) {
            int t1 = find_max(root->left);
            res = min(res, abs(t1 - root->val));
            dfs(root->left);
        } else {
            int t1 = find_min(root->right),
                    t2 = find_max(root->left),
                    t3 = min(abs(t1 - root->val), abs(t2 - root->val));
            res = min(res, t3);
            dfs(root->right);
            dfs(root->left);
        }
    }

    int getMinimumDifference(TreeNode *root) {
        res = 0x3f3f3f3f;
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
