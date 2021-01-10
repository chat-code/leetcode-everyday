/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
 * 
 * 找到递推关系：
 * d[i] = {d[j] as left, d[i-1-j] as right | 1 <= j < i}
 * 從前面的樹中找到兩棵樹，分別作爲左子樹和右子樹，然後添加一個根節點，就得到了一棵節點數爲
 * i 的滿二叉樹。這兩棵子樹的節點和爲 i-1, 因此就得到了上面的遞推關係。
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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N % 2 == 0) return res;
        vector<TreeNode*> d[25];
        d[1].push_back(new TreeNode(0));
        for (int i = 3; i <= N; i += 2) {
            for (int q = 1; q < i; q += 2) {
                int k = i - 1 - q;
                for (int j = 0; j < d[q].size(); ++j) {
                    for (int m = 0; m < d[k].size(); ++m) {
                        TreeNode *tmp = new TreeNode(0);
                        tmp->left = d[q][j];
                        tmp->right = d[k][m];
                        d[i].push_back(tmp);
                    }
                }
            }
        }
        return d[N];
    }
};
// @lc code=end

