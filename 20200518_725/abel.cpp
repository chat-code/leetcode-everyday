/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

#include <vector>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

// @lc code=start
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<int> a(k, 0);
        vector<ListNode*> res(k, nullptr);

        int length = 0;
        ListNode* cur1 = root;
        while (cur1 != nullptr) {
            length++;
            cur1 = cur1->next;
        }

        if (length < k) {
            for (int i = 0; i < length; i++) {
                a[i] = 1;
            }
        } else {
            int tmp = length / k;
            int m = length % k;
            for (int i = 0; i < k; ++i) {
                if (i < m) {
                    a[i] = tmp + 1;
                } else {
                    a[i] = tmp;
                }
            }
        }

        ListNode* cur = root, *tmp;
        for (int i = 0; i < k; ++i) {
            int len = a[i];
            if (len == 0) { continue; }
            res[i] = cur;
            len--;
            tmp = cur;
            while (len--) {
                tmp = tmp->next;
            }
            cur = tmp->next;
            tmp->next = nullptr;
        }
        return res;        
    }
};
// @lc code=end

