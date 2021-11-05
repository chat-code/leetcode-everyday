class Solution {
public:
  int lastStoneWeight(vector<int>& a) {
    priority_queue<int> q;
    for (const auto &x : a) q.push(x);

    int res {};
    while (q.size() >= 2) {
      int y = q.top();
      q.pop();
      int x = q.top();
      q.pop();

      if (y - x > 0)
        q.push(y - x);
    }

    if (q.empty()) return 0;
    else return q.top();
  }
};
