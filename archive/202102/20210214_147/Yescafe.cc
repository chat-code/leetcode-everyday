// /*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() {
    if (this->next)
      delete this->next;
    this->next = nullptr;
  }
};

// @lc code=start
// Your runtime beats 14.58 % of cpp submissions
// Your memory usage beats 68.04 % of cpp submissions (9.6 MB)

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
  ListNode* insertionSortList(ListNode* head) {
    auto fake_head = new ListNode(-10000);
    
    while (head != nullptr) {
      auto prev = fake_head;
      auto it = fake_head->next;
      auto remain = head->next;
      head->next = nullptr;

      while (it != nullptr && it != head) {
        if (head->val <= it->val) {
          head->next = it;
          break;
        }
        prev = it;
        it = it->next;
      }

      prev->next = head;
      head = remain;
    }

    return fake_head->next;
  }
};
// @lc code=end

#include <iostream>

static void printList(ListNode* r) {
  for (int cnt = 0; cnt < 100 && r != nullptr; r = r->next, ++cnt) {
    std::cout << r->val << "->";
  }
  std::endl(std::cout);
}

int main()
{
  // auto n3 = new ListNode(3, nullptr);
  // auto n2 = new ListNode(1, n3);
  // auto n1 = new ListNode(2, n2);
  // auto n0 = new ListNode(4, n1);
  ListNode *n0, *ns;
  int v;
  while (std::cin >> v) {
    if (!n0)
      ns = n0 = new ListNode(v);
    else
      ns = ns->next = new ListNode(v);
  }
  printList(n0);
  auto r = Solution().insertionSortList(n0);
  printList(r);
  delete n0;
}
