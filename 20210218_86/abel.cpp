/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode *p1, *p2, *q1, *q2, *res = new ListNode(0, head), *cur = head;

        p1 = p2 = q1 = q2 = nullptr;
        while (cur != nullptr) {
            if (cur->val >= x) {
                if (q1 == nullptr) q1 = cur;
                if (q2 == nullptr) q2 = cur;
                else q2->next = cur, q2 = cur;
            } else {
                if (p1 == nullptr) p1 = cur;
                if (p2 == nullptr) p2 = cur;
                else p2->next = cur, p2 = cur;
            }
            cur = cur->next;
        }
        if (p2 != nullptr) p2->next = q1;
        if (q2 != nullptr) q2->next = nullptr;

        if (p1 != nullptr) res->next = p1;
        else res->next = q1;

        return res->next;
    }
};
// @lc code=end

