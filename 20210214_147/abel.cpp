/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *res = new ListNode(0, head);

        ListNode *p, *q, *cur, *prev;

        prev = res;
        p = head->next;
        head->next = nullptr;

        while (p != nullptr) {
            q = p->next;
            p->next = nullptr;
            
            prev = res;
            cur = prev->next;
            while (cur != nullptr) {
                if (cur->val >= p->val) {
                    prev->next = p;
                    p->next = cur;
                    break;
                }
                prev = cur;
                cur = cur->next;
            }
            if (cur == nullptr) {
                prev->next = p;
            }

            p = q;
        }

        return res->next;
    }
};
// @lc code=end

