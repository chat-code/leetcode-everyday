/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
 */
#include <iostream>
#include <unordered_map>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* res = new ListNode(0);
        res->next = head;
        unordered_map<int, ListNode*> nset;
        int sum = 0;
        nset[sum] = res;
        for (ListNode* t = head; t != NULL; t = t->next) {
            sum += t->val;
            nset[sum] = t;
        }

        sum = 0;
        for (ListNode* t = res; t != NULL; t = t->next) {
            sum += t->val;
            unordered_map<int, ListNode*>::iterator it;
            it = nset.find(sum);
            if (it != nset.end()) {
                t->next = it->second->next;
            }
        }
        return res->next;
    }
};
// @lc code=end

