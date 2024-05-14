bool vis[1001];

class Solution {
public:
  int minimumOperations(vector<int>& nums, int start, int goal) {
    memset(vis, 0, sizeof(vis));
    
    deque<int> q;
    q.push_back(start);
    int times = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int x = q.front();
        if (x == goal) return times;
        q.pop_front();
        if (x < 0 || x > 1000 || vis[x]) continue;
        vis[x] = true;
        for (auto& n : nums) {
          q.push_back(x + n);
          q.push_back(x - n);
          q.push_back(x ^ n);
        }
      }
      ++times;
    }
    
    return -1;
  }
};
