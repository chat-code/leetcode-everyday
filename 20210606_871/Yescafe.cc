class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int fuel = startFuel;
    priority_queue<int> pq;
    int ret = 0;
    
    stations.push_back({target, 0});
    for (auto& v : stations) {
      while (!pq.empty() && fuel - v[0] < 0) {
        fuel += pq.top();
        pq.pop();
        ++ret;
      }
      
      if (fuel - v[0] < 0) {
        return -1;
      }
      
      pq.push(v[1]);
    }
    
    return ret;
  }
};
