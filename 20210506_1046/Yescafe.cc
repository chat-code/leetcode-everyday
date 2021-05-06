// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
// Memory Usage: 7.5 MB, less than 95.95% of C++ online submissions for Last Stone Weight.

#include <queue>

class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      pq.push(abs(a - b));
    }
    return pq.top();
  }
};

