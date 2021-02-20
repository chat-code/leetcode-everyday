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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return head;
    ListNode *h, *t, *q1, *q2, *cur, *p1, *p2, *p3, *res = new ListNode(0, head);
    int K = --k;

    h = res, t = h->next;
    while (true) {
      k = K;
      q1 = t, cur = t;
      while (k-- && cur != nullptr) cur = cur->next;
      if (k > 0 || cur == nullptr) {
        h->next = t;
        return res->next;
      }

      q2 = cur; t = cur->next;
      h->next = q2, h = q1;

      p1 = q1, p2 = p1->next;
      while (p2 != t) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
      }
    }

    return res->next;
  }
};
