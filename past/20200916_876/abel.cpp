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
  ListNode* middleNode(ListNode* head) {
    ListNode *p1 = head, *p2 = head;
    stack<ListNode*> st;

    while (p2 != nullptr) {
      st.push(p2);
      p2 = p2->next;
    }

    while (!st.empty()) {
      p2 = st.top();
      st.pop();

      if (p1 == p2) return p1;
      p1 = p1->next;
      if (p1 == p2) return p1;
    }

    return nullptr;
  }
};
