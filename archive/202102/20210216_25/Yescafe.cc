/*
Runtime: 12 ms, faster than 95.41% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 11.5 MB, less than 78.51% of C++ online submissions for Reverse Nodes in k-Group.
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1 || head->next == nullptr)
      return head;   // specified
    int length = 0;
    auto itr = head;
    while (itr != nullptr) {
      ++length;
      itr = itr->next;
    }
    
    if (length < k) return head;
    
    auto remain = head;
    ListNode* new_head = nullptr;
    ListNode* prev_parts_tail = nullptr;
    for (int s = 0; s < length / k; ++s) {
      ListNode* parts_head = nullptr;
      ListNode* parts_tail = remain;
      
      for (int i = 0; i < k; ++i) {
        auto tmp = remain->next;
        remain->next = parts_head;
        parts_head = remain;
        remain = tmp;
        if (s == 0 && i == k - 1) new_head = parts_head;
      }
      
      if (prev_parts_tail) prev_parts_tail->next = parts_head;
      prev_parts_tail = parts_tail;
    }
    
    if (remain) prev_parts_tail->next = remain;
    
    return new_head;
  }
};
