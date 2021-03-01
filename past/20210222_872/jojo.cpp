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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        getLeaf(root1, r1);
        getLeaf(root2, r2);
        if (r1.size() != r2.size()) return false;
        for(int i = 0; i < r1.size(); i++){
            if(r1[i] != r2[i]){
                return false;
            }
        }
        return true;
    }
    // 前序遍历
    void getLeaf(TreeNode* root, vector<int>& ivec) {
        if (root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            ivec.push_back(root->val);
        }
        getLeaf(root->left, ivec);
        getLeaf(root->right, ivec);
    }
};