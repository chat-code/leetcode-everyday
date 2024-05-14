/*
Runtime: 4 ms, faster than 59.80% of C++ online submissions for Reverse Linked List II.
Memory Usage: 7.5 MB, less than 72.45% of C++ online submissions for Reverse Linked List II.
*/

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
    if (left == right) return head;    // specified
    auto begin = head, lefter = head;
    for (int i = 1; i < left; ++i) {
      lefter = begin;
      begin = begin->next;
    }
    
    int count = right - left + 1;
    auto remain = begin;
    
    ListNode* reversed = nullptr;
    while (count--) {
      auto tmp = remain;
      remain = remain->next;
      tmp->next = reversed;
      reversed = tmp;
    }
    begin->next = remain;  // `begin` will be the new tail of the reversed part
    
    if (left == 1) {
      return reversed;
    }
    lefter->next = reversed;
    return head;
  }
};
