/*
Runtime: 36 ms, faster than 96.04% of C++ online submissions for IPO.
Memory Usage: 23.2 MB, less than 65.68% of C++ online submissions for IPO.
*/

#include <queue>
#include <algorithm>

struct Project {
  int p, c;
};

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    std::vector<Project> ivec;
    for (int i = 0; i < profits.size(); ++i) {
      ivec.push_back({profits[i], capital[i]});
    }
    std::sort(ivec.begin(), ivec.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.c < rhs.c;
    });
    
    std::priority_queue<int> pq;
    auto itr = ivec.begin();
    while (k--) {
      while (itr != ivec.end() && itr->c <= w) {
        pq.push(itr++->p);
      }
      if (pq.empty()) break;
      w += pq.top();
      pq.pop();
    }
    return w;
  }
};
