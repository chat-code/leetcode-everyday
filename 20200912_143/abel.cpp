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
  void reorderList(ListNode* head) {
    if (head == nullptr) return;

    stack<ListNode*> st;
    ListNode* res = new ListNode(0, head);

    ListNode* prev = res, *p1 = head, *p2 = head;

    while (p2 != nullptr) {
      st.push(p2);
      p2 = p2->next;
    }

    while (!st.empty()) {
      p2 = st.top();
      st.pop();

      if (p1 == p2) {
        prev->next = p1;
        prev = prev->next;
        prev->next = nullptr;
        break;
      }

      bool flag = false;
      flag = p1->next == p2;

      prev->next = p1;
      p1 = p1->next;

      prev = prev->next;
      prev->next = p2;
      prev = prev->next;

      if (flag) {
        prev->next = nullptr;
        break;
      }
    }
  }
};
