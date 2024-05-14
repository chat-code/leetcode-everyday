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
  ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0) return head;

    int cnt = 0, len = 0;
    ListNode* p1 = head, *p2 = head;

    while (cnt < k && p2 != nullptr) {
      p2 = p2->next;
      ++cnt;
    }

    if (cnt < k) {
      len = cnt;
      if (len == 0) return head;

      k = k % len;
      if (k == 0) return head;

      p2 = head;
      cnt = 0;
      while (cnt < k && p2 != nullptr) {
        p2 = p2->next;
        ++cnt;
      }
    }

    if (cnt == k) {
      if (p2 == nullptr) return head;

      while (p2->next != nullptr) {
        p2 = p2->next;
        p1 = p1->next;
      }

      p2->next = head;
      head = p1->next;
      p1->next = nullptr;
      return head;
    }

    return nullptr;
  }
};
