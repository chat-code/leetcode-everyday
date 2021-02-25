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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;

    stack<ListNode*> st;
    ListNode *p1 = head, *p2 = head;

    while (p2 != nullptr) {
      st.push(p2);
      p2 = p2->next;
    }

    while (!st.empty()) {
      p2 = st.top();
      st.pop();

      if (p1 == p2) return true;

      if (p2->val != p1->val) return false;
      p1 = p1->next;

      if (p1 == p2) return true;
    }

    return false;
  }
};
