/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stack>

using namespace std;

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> st1, st2;
    ListNode* res, *cur = l1;
    res = new ListNode(0);

    while (cur != nullptr) {
      st1.push(cur->val);
      cur = cur->next;
    }

    cur = l2;
    while (cur != nullptr) {
      st2.push(cur->val);
      cur = cur->next;
    }

    int t = 0;
    stack<int> st3;
    while (!st1.empty() && !st2.empty()) {
      int x1 = st1.top(), x2 = st2.top();
      st1.pop();
      st2.pop();
      t += (x1 + x2);
      st3.push(t % 10);
      t /= 10;
    }
    while (!st1.empty()) {
      t += st1.top();
      st1.pop();
      st3.push(t % 10);
      t /= 10;
    }
    while (!st2.empty()) {
      t += st2.top();
      st2.pop();
      st3.push(t % 10);
      t /= 10;
    }
    if (t) st3.push(t);

    ListNode* tmp;
    cur = res;
    while (!st3.empty()) {
      tmp = new ListNode(st3.top());
      st3.pop();
      cur->next = tmp;
      cur = tmp;
    }

    return res->next;
  }
};
