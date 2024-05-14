//完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。 
//
// 设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作： 
//
// 
// CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构； 
// CBTInserter.insert(int v) 向树中插入一个新节点，节点类型为 TreeNode，值为 v 。使树保持完全二叉树的状态，并返回插入的
//新节点的父节点的值； 
// CBTInserter.get_root() 将返回树的头节点。 
// 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
//输出：[null,1,[1,2]]
// 
//
// 示例 2： 
//
// 输入：inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4
//,5,6]],[7],[8],[]]
//输出：[null,3,4,[1,2,3,4,5,6,7,8]]
// 
//
// 
//
// 提示： 
//
// 
// 最初给定的树是完全二叉树，且包含 1 到 1000 个节点。 
// 每个测试用例最多调用 CBTInserter.insert 操作 10000 次。 
// 给定节点或插入节点的每个值都在 0 到 5000 之间。 
// 
// Related Topics 树 
// 👍 36 👎 0

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

class CBTInserter {
public:
    CBTInserter(TreeNode *root) : head(root) {
    }

    int insert(int v) {
        TreeNode *t = head;
        queue < TreeNode * > que;
        que.push(t);
        int res;
        TreeNode *v1 = new TreeNode(v);
        TreeNode *tmp;
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            if (tmp->left == nullptr) {
                tmp->left = v1;
                res = tmp->val;
                return res;
            } else if (tmp->right == nullptr) {
                tmp->right = v1;
                res = tmp->val;
                return res;
            }
            que.push(tmp->left);
            que.push(tmp->right);
        }
        return res;
    }

    TreeNode *get_root() {
        return head;
    }

private:
    TreeNode *head;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
//leetcode submit region end(Prohibit modification and deletion)
