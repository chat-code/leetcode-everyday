// Runtime: 512 ms, faster than 5.84% of C++ online submissions for Find Eventual Safe States.
// Memory Usage: 62 MB, less than 23.15% of C++ online submissions for Find Eventual Safe States.

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ret;
    set<int> cyc;
    set<int> vis;
    for (int i = 0; i < graph.size(); ++i) {
      if (!find_cycle(graph, cyc, vis, i)) {
        ret.push_back(i);
      }
    }
    return ret;
  }
private:
  
  bool find_cycle(vector<vector<int>>& graph, set<int>& cyc, set<int>& vis, int node) {
    bool ret = false;
    cyc.insert(node);
    
    for (auto&& i : graph[node]) {
      if (vis.find(i) != vis.end()) {  // i was visited
        continue;
      }
      if (cyc.find(i) != cyc.end() || find_cycle(graph, cyc, vis, i)) {
        return true;
      }
    }
    
    vis.insert(node);
    cyc.erase(node);
    
    return false;
  }
};

