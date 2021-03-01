/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 * 
 * 求出所有的子樹的節點和，找到出現次數最多的和
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
    int cnt;
    map<int, int> nm;
    int dfs(TreeNode * root) {
        if (root == nullptr) return 0;
        int left = 0, right = 0, sum = 0;
        if (root->left == nullptr && root->right == nullptr) {
            sum = root->val;
            nm[sum]++;
            cnt = max(cnt, nm[sum]);
            return sum;
        }
        left = dfs(root->left);
        right = dfs(root->right);
        sum = left + right + root->val;
        nm[sum]++;
        cnt = max(nm[sum], cnt);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        cnt = 0;
        VI res;
        dfs(root);
        for (auto &x : nm) {
            if (x.second == cnt) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};
// @lc code=end

