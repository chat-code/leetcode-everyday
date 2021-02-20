/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

const int N = 10010;
int stk[N];

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        VI a, res;
        if (head == nullptr) return res;

        ListNode *cur = head;
        while (cur != nullptr) {
            a.push_back(cur->val), cur = cur->next;
            res.push_back(0);
        }

        int len = a.size();
        a.push_back(INT_MAX);
        int tt = 0;
        stk[++tt] = len;
        for (int i = len - 1; i >= 0; i--) {
            while (tt && a[i] >= a[stk[tt]]) --tt;
            if (tt == 1) res[i] = 0;
            else res[i] = a[stk[tt]];
            stk[++tt] = i;
        }
        return res;
    }
};
// @lc code=end

