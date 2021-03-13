class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      map<string, string> g;
      vector<string> v;
      for (auto &p : paths) {
        g[p[0]] = p[1];
        v.push_back(p[0]);
        v.push_back(p[1]);
      }
      for (auto &x : v) {
        if (g.find(x) == g.end()) return x;
      }
      return "";
    }
};
