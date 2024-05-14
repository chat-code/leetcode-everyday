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
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
      return {-1, -1};
    }
    ListNode *ls = head, *curr = head->next, *rs = head->next->next;
    // vector<int> pos;
    int first = -1, past = -1;
    int min_dif = 1e9 + 7;
    int i = 1;
    do {
      if (compare(ls, curr, rs)) {
        // pos.push_back(i);
        if (first == -1) {
          past = first = i;
        } else {
          min_dif = min(min_dif, i - past);
          past = i;
        }
      }
      ls = curr, curr = rs, rs = rs->next;
      ++i;
    } while (rs != nullptr);

    if (first == past) {
      return {-1, -1};
    }
    return {min_dif, past - first};
    
    // if (pos.size() < 2) {
    //   return {-1, -1};
    // }
    
    // vector<int> dif(pos.size(), 0);
    // adjacent_difference(pos.begin(), pos.end(), dif.begin());
    // return {*min_element(dif.begin() + 1, dif.end()), pos.back() - pos.front()};
  }
  
private:
  int compare(ListNode* ls, ListNode* curr, ListNode* rs) {
    int l = compare(ls->val, curr->val);
    int r = compare(rs->val, curr->val);
    return l == r && l != 0;
  }
  int compare(int a, int b) {
    if (a < b) return -1;
    else if (a > b) return 1;
    return 0;
  }
};
