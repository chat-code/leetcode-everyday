/*
Runtime: 4 ms, faster than 93.01% of C++ online submissions for Partition List.
Memory Usage: 10.2 MB, less than 75.29% of C++ online submissions for Partition List.
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
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) return nullptr;
    auto ls = new ListNode(), ge = new ListNode();
    auto itl = ls, itg = ge;
    auto remain = head;
    while (remain != nullptr) {
      if (remain->val < x)
        itl = itl->next = remain;
      else
        itg = itg->next = remain;
      remain = remain->next;
    }
    itg->next = nullptr;
    
    if (ls->next == nullptr)
      return ge->next;
    itl->next = ge->next;
    
    return ls->next;
  }
};
