class Solution {
public:
  int scheduleCourse(vector<vector<int>>& c) {
    sort(c.begin(), c.end(), [](vector<int>& a, vector<int>& b) {
        return a.back() < b.back();
    });
    
    priority_queue<int> pq;
    int s = 0;
    for (auto& cc : c) {
      int& du = cc.front();
      int& ld = cc.back();
      if (s + du <= ld) {
        s += du;
        pq.push(du);
      } else if (!pq.empty() && pq.top() > du) {
        s -= pq.top() - du;
        pq.pop();
        pq.push(du);
      }
    }
    return pq.size();
  }
};

