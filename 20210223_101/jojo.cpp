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
    bool isSymmetric(TreeNode* root) {
        return equalLeafP(root->left, root->right);
    }
    // 从跟子树的两个叶子节点开始递归。
    bool equalLeafP (TreeNode* leftNode, TreeNode* rightNode) {
        // 若其中有一个节点为nullptr，则不能用nodeTree->val来测试。
        if(leftNode == nullptr || rightNode == nullptr) return leftNode == rightNode;
        // 简单的比较值然后递归。
        if(leftNode->val != rightNode->val) return false;
        return equalLeafP(leftNode->left, rightNode->right) && equalLeafP(leftNode->right, rightNode->left);
    }
};