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
  ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return nullptr;
    ListNode* res = new ListNode(0, head);

    ListNode *prev = res, *cur = head;
    while (cur != nullptr) {
      if (cur->val == val) cur = cur->next;
      else {
        prev->next = cur;
        prev = cur;
        cur = cur->next;
      }
    }
    if (prev != nullptr && prev->next != nullptr) {
      prev->next = nullptr;
    }

    return res->next;
  }
};
