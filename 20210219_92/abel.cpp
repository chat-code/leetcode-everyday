/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;
        ListNode *res = new ListNode(0, head), *h = res, *t = res;
        left--, right++;
        while (left--) h = h->next;
        while (right--) t = t->next;

        ListNode *p1 = h, *p2 = p1->next, *p3 = nullptr;
        while (p2 != t && p2 != nullptr) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        p2 = h->next;
        h->next = p1;
        p2->next = t;

        return res->next;
    }
};
// @lc code=end

