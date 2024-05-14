/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void connect(ListNode* &cur, ListNode* &next) {
        cur->next = next;
        cur = cur->next;
        next = next->next;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* res = new ListNode(),
                *cur = res;
        while (l1 != nullptr ||
            l2 != nullptr) { 
            if (l1 == nullptr) {
                cur->next = l2;
                break;
            } else if (l2 == nullptr) {
                cur->next = l1;
                break;
            } else {
                ListNode* tmp;
                if (l1->val <= l2->val) {
                    connect(cur, l1);
                } else {
                    connect(cur, l2);
                }
            }
        }
        ListNode* t_res = res->next;
        delete res;
        return t_res;
    }
};
// @lc code=end
