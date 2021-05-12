// Runtime: 104 ms, faster than 44.17% of C++ online submissions for Distant Barcodes.
// Memory Usage: 44.5 MB, less than 23.61% of C++ online submissions for Distant Barcodes.

struct Comp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
  }
}; 

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
    
    map<int, int> counter;
    for (auto&& barcode : barcodes) {
      ++counter[barcode];
    }
    for (auto&& p : counter) {
      pq.push(p);
    }

    while (res.size() != barcodes.size()) {
      auto top1 = pq.top();
      res.push_back(top1.first);
      --top1.second;
      pq.pop();
      if (!pq.empty()) {
        auto top2 = pq.top();
        res.push_back(top2.first);
        --top2.second;
        pq.pop();
        if (top1.second > 0)
          pq.push(top1);
        if (top2.second > 0)
          pq.push(top2);
      } else {
        if (top1.second > 0)
          pq.push(top1); 
      }
    }

    return res;
  }
};

