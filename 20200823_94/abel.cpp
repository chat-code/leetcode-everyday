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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
using VI = vector<int>;
using VS = vector<string>;
TreeNode* st[1000];

class Solution {
public:
    vector<int> inorderTraversalV1(TreeNode* root) {
        VI res;
        stack<TreeNode*> st;
        while (true) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            if (!st.empty()) {
                TreeNode* t = st.top();
                st.pop();
                res.push_back(t->val);
                root = t->right;
            } else break;
        }
        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        VI res;
        int tt = 0;
        while (true) {
            while (root != nullptr) {
                st[++tt] = (root);
                root = root->left;
            }

            if (tt) {
                TreeNode* t = st[tt--];
                res.push_back(t->val);
                root = t->right;
            } else break;
        }
        return res;
    }
};
