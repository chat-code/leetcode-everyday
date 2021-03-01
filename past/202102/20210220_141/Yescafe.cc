/*
Runtime: 8 ms, faster than 86.06% of C++ online submissions for Linked List Cycle.
Memory Usage: 8 MB, less than 34.92% of C++ online submissions for Linked List Cycle.
*/

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
  bool hasCycle(ListNode *head) {
    if (head == NULL) return false;  // specified
    ListNode *hare, *turtle;
    hare = turtle = head;
    
    do {
      if (hare->next == NULL) return false;
      hare = hare->next;
      if (hare->next == NULL) return false;
      hare = hare->next;
      turtle = turtle->next;
    } while (hare != turtle);
    return true;
  }
};
